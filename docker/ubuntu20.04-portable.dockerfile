FROM ubuntu:20.04

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
	git clone https://github.com/MacroUniverse/SLISC --depth 1 && \
	git clone https://github.com/MacroUniverse/SLISC-libs-x64-ubuntu20.04 --depth 1

ARG INSTALL_DIR=/home/$DOCKER_USER/SLISC-libs-x64-ubuntu20.04

# set number of threads for compilation
ARG NCPU=8

# ======== SLISC 32-bit dynamic no-quadmath ========
RUN cd ~/SLISC-libs-x64-ubuntu20.04 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && touch SLISC/*.h && \
	rm -f *.o && make -j$NCPU && \
	./main.x < input.inp

# ======== SLISC 64-bit dynamic quadmath ========
RUN cd ~/SLISC-libs-x64-ubuntu20.04 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && cp SLISC-long64-quad/*.h SLISC/ && \
	rm -f *.o && make opt_long32=false opt_quadmath=true -j$NCPU && \
	./main.x < input.inp

# ======== SLISC 32-bit dynamic no-quadmath ========
RUN cd ~/SLISC-libs-x64-ubuntu20.04 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && touch SLISC/*.h && \
	rm -f *.o && make opt_static=true -j$NCPU && \
	./main.x < input.inp

# ======== SLISC 64-bit dynamic quadmath ========
RUN cd ~/SLISC-libs-x64-ubuntu20.04 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && cp SLISC-long64-quad/*.h SLISC/ && \
	rm -f *.o && make opt_static=true opt_long32=false opt_quadmath=true -j$NCPU && \
	./main.x < input.inp
