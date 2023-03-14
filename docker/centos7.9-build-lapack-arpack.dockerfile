## run folloing in SLISC to build and export library

# sudo docker build -t addiszx/slisc0:centos7.9-build-lapack-arpack -f docker/centos7.9-build-lapack-arpack.dockerfile . | tee docker-centos7.9-build-lapack-arpack.log
# sudo docker run --name centos7.9-build-lapack-arpack -itd addiszx/slisc0:centos7.9-build-lapack-arpack bash
# sudo docker cp centos7.9-build-lapack-arpack:/home/docker/libs/lapack-shared-3.10.1.tar.gz .
# sudo docker cp centos7.9-build-lapack-arpack:/home/docker/libs/lapack-static-3.10.1.tar.gz .
# sudo docker cp centos7.9-build-lapack-arpack:/home/docker/libs/lapack64-shared-3.10.1.tar.gz .
# sudo docker cp centos7.9-build-lapack-arpack:/home/docker/libs/lapack64-static-3.10.1.tar.gz .
# sudo docker cp centos7.9-build-lapack-arpack:/home/docker/libs/arpack-ng-3.8.0.tar.gz .
# sudo docker rm -f centos7.9-build-lapack-arpack

FROM centos:7.9.2009

RUN yum install -y https://repo.ius.io/ius-release-el7.rpm
RUN yum install -y centos-release-scl

# includes g++ and gfortran 9.3.1, GDB 8.3 make 4.2.1
# ref: https://access.redhat.com/documentation/en-us/red_hat_developer_toolset/9/html-single/user_guide/index
RUN yum install -y devtoolset-9

# this set the shel for rest of the Dockerfile, but not for `docker run`
# equivalent to `scl enable devtoolset-9 bash` in a bash session
SHELL [ "scl", "enable", "devtoolset-9" ]

RUN yum install -y git vim time wget mlocate automake libtool lzip

# ======== New User ========
# create `docker` as sudoer, use bash by default
# no password required for sudo command

RUN yum install -y sudo
ARG DOCKER_UID=1000
ARG DOCKER_USER=docker
ARG DOCKER_PASSWD=docker
RUN useradd -u $DOCKER_UID -m $DOCKER_USER --shell /bin/bash -G wheel,root && \
    echo "$DOCKER_USER:$DOCKER_PASSWD" | chpasswd && \
    echo "$DOCKER_USER ALL=(ALL) ALL" >> /etc/sudoers && \
    echo "$DOCKER_USER ALL=NOPASSWD: ALL" >> /etc/sudoers

USER ${DOCKER_USER}

ARG INSTALL_DIR=/home/$DOCKER_USER/libs
RUN mkdir -p $INSTALL_DIR

# set number of threads for compilation
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
	mkdir $INSTALL_DIR/lapack64-shared-3.10.1 && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack64-shared-3.10.1 -DBUILD_INDEX64=ON -DBUILD_SHARED_LIBS=ON -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 32bit dynamic (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack-shared-3.10.1 && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack-shared-3.10.1 -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=ON -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 64bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack64-static-3.10.1 && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack64-static-3.10.1 -DBUILD_INDEX64=ON -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

# ======== (C)BLAS and LAPACK(E) 32bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack-static-3.10.1 && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack-static-3.10.1 -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j$NCPU && make install

RUN ln -s lib64 $INSTALL_DIR/lapack-shared-3.10.1/lib && \
	ln -s lib64 $INSTALL_DIR/lapack-static-3.10.1/lib && \
	ln -s lib64 $INSTALL_DIR/lapack64-shared-3.10.1/lib && \
	ln -s lib64 $INSTALL_DIR/lapack64-static-3.10.1/lib

# ======== Arpack-NG 32 bit dynamic ========
RUN cd ~/ && \
 	wget -q https://github.com/opencollab/arpack-ng/archive/refs/tags/3.8.0.tar.gz && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack-ng-shared-3.8.0 && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack-shared-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack-shared-3.10.1/lib/ && \
	./configure --prefix=$INSTALL_DIR/arpack-ng-shared-3.8.0 && \
	make -j$NCPU && make check -j$NCPU && make install

# ======== Arpack-NG 32 bit static ========
# make check will fail for static lib
RUN cd ~/ && \
	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack-ng-static-3.8.0 && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack-static-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack-static-3.10.1/lib/ && \
	./configure --prefix=$INSTALL_DIR/arpack-ng-static-3.8.0 --enable-static=yes --enable-shared=no && \
	make -j$NCPU && make install

# ======== Arpack-NG 64 bit dynamic ========
RUN cd ~/ && \
 	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack-ng64-shared-3.8.0 && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export INTERFACE64=1 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-shared-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-shared-3.10.1/lib/ && \
	./configure --prefix=$INSTALL_DIR/arpack-ng64-shared-3.8.0 --with-blas=blas64 --with-lapack=lapack64 && \
	make -j$NCPU

RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-shared-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-shared-3.10.1/lib/ && \
	make check && make install

RUN cd $INSTALL_DIR/arpack-ng64-shared-3.8.0/lib && \
	ln -s libarpack.so libarpack64.so

# ======== Arpack-NG 64 bit static ========
# make check will fail for static lib
RUN cd ~/ && \
 	rm -rf ~/arpack-ng-3.8.0 && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack-ng64-static-3.8.0 && \
	sh bootstrap

# delete line 25613 to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export INTERFACE64=1 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-static-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-static-3.10.1/lib/ && \
	./configure --prefix=$INSTALL_DIR/arpack-ng64-static-3.8.0  --with-blas=blas64 --with-lapack=lapack64 --enable-static=yes --enable-shared=no && \
	make -j$NCPU

RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack64-static-3.10.1/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack64-static-3.10.1/lib/ && \
	make install

RUN cd $INSTALL_DIR/arpack-ng64-static-3.8.0 /lib && \
	ln -s libarpack.a libarpack64.a
