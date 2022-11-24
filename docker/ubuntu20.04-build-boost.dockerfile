FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y git vim time \
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

ARG INSTALL_DIR=/home/$DOCKER_USER/libs
RUN mkdir -p $INSTALL_DIR

# set number of threads for compilation
ARG NCPU=8

# ======== Boost ========
# ./bootstrap.sh ... --with-libraries=filesystem to select sub lib
RUN cd ~ && \
	wget -q https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/boost_1_80_0.tar.gz
	
RUN cd ~ && \
	tar -xzf boost_1_80_0.tar.gz && cd boost_1_80_0 && \
	mkdir $INSTALL_DIR/boost-1.80.0 && \
	./bootstrap.sh --prefix=$INSTALL_DIR/boost-1.80.0 && \
	./b2 install -j$NCPU
