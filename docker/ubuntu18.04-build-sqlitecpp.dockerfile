# sudo docker build -t addiszx/slisc:ubuntu22.04-build-sqlitecpp -f docker/ubuntu22.04-build-sqlitecpp.dockerfile .

FROM ubuntu:18.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y git vim time \
	wget

RUN apt install -y g++ make

RUN apt install -y cmake

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

ARG INSTALL_DIR=/home/$DOCKER_USER/libs
RUN mkdir -p $INSTALL_DIR

# set number of threads for compilation
ARG NCPU=8

# ======== Sqlite ========
RUN cd ~ && \
	wget -q --no-check-certificate https://github.com/SRombauts/SQLiteCpp/archive/refs/tags/3.2.1.tar.gz && \
	tar -xzf ./3.2.1.tar.gz && \
	mkdir $INSTALL_DIR/sqlitecpp-3.2.1 && cd SQLiteCpp-3.2.1

RUN	cd ~/SQLiteCpp-3.2.1 && \
	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=$INSTALL_DIR/sqlitecpp-3.2.1 -D SQLITECPP_RUN_CPPCHECK=OFF -D SQLITECPP_RUN_CPPLINT=OFF . && \
	make -j$NCPU && make install
