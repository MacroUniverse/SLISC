未完成

FROM ubuntu:22.04

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

# ======== GMP ========
RUN cd ~/ && wget -q https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz && \
	lzip -d gmp-6.2.1.tar.lz && \
	tar -xf gmp-6.2.1.tar && cd gmp-6.2.1 && \
	mkdir $INSTALL_DIR/gmp && \
	./configure --prefix=$INSTALL_DIR/gmp && \
	make -j$NCPU && make check -j$NCPU && make install

# ======== MPFR ========
RUN cd ~/ && \
	wget -q https://www.mpfr.org/mpfr-4.1.0/mpfr-4.1.0.tar.gz && \
	tar -xzf mpfr-4.1.0.tar.gz && cd mpfr-4.1.0 && \
	mkdir $INSTALL_DIR/mpfr && \
	./configure --prefix=$INSTALL_DIR/mpfr --with-gmp=$INSTALL_DIR/gmp && \
	make -j$NCPU && make check -j$NCPU && make install

# ======== Flint3 ========
RUN cd ~ && wget -q https://github.com/flintlib/flint/releases/download/v3.1.3-p1/flint-3.1.3-p1.tar.gz && \
	tar -xzf flint-3.1.3-p1.tar.gz && cd flint-3.1.3-p1/ && \
	mkdir $INSTALL_DIR/flint && \
	# ./configure --prefix=/root/tmp/flint-3.1.3-p1/ --with-gmp=/mnt/g/github/SLISC-libs-x64-ubuntu22.04/gmp-6.1.2 --with-mpfr=/mnt/g/github/SLISC-libs-x64-ubuntu22.04/mpfr-4.1.0
	./configure --prefix=$INSTALL_DIR/flint --with-gmp=$INSTALL_DIR/gmp --with-mpfr=$INSTALL_DIR/mpfr && \
	make -j$NCPU && make check -j$NCPU && make install
