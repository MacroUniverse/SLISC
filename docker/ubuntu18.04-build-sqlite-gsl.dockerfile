FROM ubuntu:18.04

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

ARG NCPU=8

# ======== Sqlite ========
RUN cd ~ && \
	wget -q --no-check-certificate https://www.sqlite.org/2022/sqlite-autoconf-3400000.tar.gz && \
	tar -xzf ./sqlite-autoconf-3400000.tar.gz && \
	mkdir $INSTALL_DIR/sqlite-3.40.0 && cd sqlite-autoconf-3400000 && \
	./configure --prefix=$INSTALL_DIR/sqlite-3.40.0 --enable-static=yes && \
	make -j$NCPU && make install

# ======== GSL ========
RUN	cd ~/ && wget -q https://mirror.ibcp.fr/pub/gnu/gsl/gsl-2.7.1.tar.gz && \
	tar -xzf gsl-2.7.1.tar.gz && cd gsl-2.7.1 && \
	mkdir $INSTALL_DIR/gsl && \
	./configure --prefix=$INSTALL_DIR/gsl && \
	make -j$NCPU && make check -j$NCPU && make install
