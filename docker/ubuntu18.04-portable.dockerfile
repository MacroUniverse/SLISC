FROM ubuntu:18.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y git vim time libsqlite3-dev libboost-filesystem-dev \
	wget mlocate automake libtool lzip

RUN apt install -y g++ gfortran make

# ======== New User ========
# create `docker` as sudoer, use bash by default
# no password required for sudo command

RUN apt install -y sudo
ARG DOCKER_UID=1000
ARG DOCKER_USER=docker
ARG DOCKER_PASSWD=docker
RUN useradd -u $DOCKER_UID -m $DOCKER_USER --shell /bin/bash && echo "$DOCKER_USER:$DOCKER_PASSWD" | chpasswd && echo "$DOCKER_USER ALL=(ALL) ALL" >> /etc/sudoers

USER ${DOCKER_USER}
SHELL ["/bin/bash", "-c"] # --shell /bin/bash didn't work

RUN	cd ~/ && \
	git clone https://github.com/MacroUniverse/SLISC0 --depth 1 && \
	git clone https://github.com/MacroUniverse/SLISC0-libs-x64-ubuntu18.04 --depth 1

ARG INSTALL_DIR=/home/$DOCKER_USER/SLISC0-libs-x64-ubuntu18.04

# ======== SLISC ========
RUN cd $INSTALL_DIR && source setup.sh && \
	cd ~/SLISC0 && \
	git pull origin && touch SLISC/*.h && \
	source make/set_path2.sh && \
	make -j`getconf _NPROCESSORS_ONLN` opt_asan=false && \
	./main.x < input.inp

RUN cd $INSTALL_DIR && source setup.sh && \
	cd ~/SLISC0 && \
	cp SLISC-long64-quad/*.h SLISC/ && \
	source make/set_path2.sh && \
	make -j`getconf _NPROCESSORS_ONLN` opt_long32=false opt_quadmath=true opt_asan=false && \
	./main.x < input.inp
