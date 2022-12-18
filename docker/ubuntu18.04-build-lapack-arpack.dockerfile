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

# ======== CMake ========
RUN cd ~/ && \
	wget -q https://github.com/Kitware/CMake/releases/download/v3.25.0-rc4/cmake-3.25.0-rc4-linux-x86_64.tar.gz && \
	tar -xzf cmake-3.25.0-rc4-linux-x86_64.tar.gz && \
	ln -s ~/cmake-3.25.0-rc4-linux-x86_64/bin/cmake ~ && \
	rm cmake-3.25.0-rc4-linux-x86_64.tar.gz

# ======== (C)BLAS and LAPACK(E) 64bit dynamic (reference) ========
# `make check` is not defined
RUN	cd ~/ && \
	wget -q https://github.com/Reference-LAPACK/lapack/archive/refs/tags/v3.10.1.tar.gz && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack64-so && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack64-so -DBUILD_INDEX64=ON -DBUILD_SHARED_LIBS=ON -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 32bit dynamic (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack32-so && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack32-so -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=ON -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 64bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack64-a && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack64-a -DBUILD_INDEX64=ON -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 32bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack32-a && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack32-a -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== Arpack-NG 32 bit dynamic ========
RUN cd ~/ && \
 	wget -q https://github.com/opencollab/arpack-ng/archive/refs/tags/3.8.0.tar.gz && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack32-so && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack32-so/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack32-so/lib/ && \
	sed -i '25613d' ./configure && \
	./configure --prefix=$INSTALL_DIR/arpack32-so && \
	make -j$NCPU && make check -j$NCPU && make install

# ======== Arpack-NG 32 bit static ========
# make check will fail for static lib
RUN cd ~/ && \
	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack32-a && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack32-a/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack32-a/lib/ && \
	sed -i '25613d' ./configure && \
	./configure --prefix=$INSTALL_DIR/arpack32-a --enable-static=yes --enable-shared=no && \
	make -j$NCPU && make install

# ======== Arpack-NG 64 bit dynamic ========
RUN cd ~/ && \
 	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack64-so && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export INTERFACE64=1 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-so/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-so/lib/ && \
	sed -i '25613d' ./configure && \
	./configure --prefix=$INSTALL_DIR/arpack64-so --with-blas=blas64 --with-lapack=lapack64 && \
	make -j$NCPU

RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-so/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-so/lib/ && \
	make check && make install

RUN cd $INSTALL_DIR/arpack64-so/lib && \
	ln -s libarpack.so libarpack64.so

# ======== Arpack-NG 64 bit static ========
# make check will fail for static lib
RUN cd ~/ && \
 	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack64-a && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export INTERFACE64=1 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-a/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-a/lib/ && \
	sed -i '25613d' ./configure && \
	./configure --prefix=$INSTALL_DIR/arpack64-a --with-blas=blas64 --with-lapack=lapack64 --enable-static=yes --enable-shared=no && \
	make -j$NCPU

RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-a/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-a/lib/ && \
	make install

RUN cd $INSTALL_DIR/arpack64-a/lib && \
	ln -s libarpack.a libarpack64.a
