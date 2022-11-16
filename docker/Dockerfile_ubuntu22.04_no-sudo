FROM ubuntu:22.04

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
	git clone https://github.com/MacroUniverse/Arpack_test --depth 1 && \
	git clone https://github.com/MacroUniverse/EigenTest --depth 1 && \
	git clone https://github.com/MacroUniverse/boost-headers --depth 1

ARG INSTALL_DIR=/home/$DOCKER_USER/libs
RUN mkdir -p $INSTALL_DIR

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
	cd ~/lapack-build && make -j12 && make install

# ======== (C)BLAS and LAPACK(E) 32bit dynamic (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack32-so && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack32-so -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=ON -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j12 && make install

# ======== (C)BLAS and LAPACK(E) 64bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack64-a && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack64-a -DBUILD_INDEX64=ON -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j12 && make install

# ======== (C)BLAS and LAPACK(E) 32bit static (reference) ========
RUN cd ~/ && \
	rm -rf lapack-3.10.1 && rm -rf lapack-build && \
	tar -xzf v3.10.1.tar.gz && \
	mkdir lapack-build && cd lapack-build && \
	mkdir $INSTALL_DIR/lapack32-a && \
	~/cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR/lapack32-a -DBUILD_INDEX64=OFF -DBUILD_SHARED_LIBS=OFF -DLAPACKE=ON -DCBLAS=ON  ../lapack-3.10.1/ && \
	cd ~/lapack-build && make -j12 && make install

# TODO: these are not needed on ubuntu
RUN ln -s lib64 $INSTALL_DIR/lapack32-so/lib && \
	ln -s lib64 $INSTALL_DIR/lapack32-a/lib && \
	ln -s lib64 $INSTALL_DIR/lapack64-so/lib && \
	ln -s lib64 $INSTALL_DIR/lapack64-a/lib

# ======== GSL ========
RUN	cd ~/ && wget -q https://mirror.ibcp.fr/pub/gnu/gsl/gsl-2.7.1.tar.gz && \
	tar -xzf gsl-2.7.1.tar.gz && cd gsl-2.7.1 && \
	mkdir $INSTALL_DIR/gsl && \
	./configure --prefix=$INSTALL_DIR/gsl && \
	make -j12 && make check -j12 && make install

# ======== Arpack-NG ========
# --with-blas --with-lapack will not work
RUN cd ~/ && \
 	wget -q https://github.com/opencollab/arpack-ng/archive/refs/tags/3.8.0.tar.gz && \
 	tar -xzf 3.8.0.tar.gz && cd arpack-ng-3.8.0 && \
	mkdir $INSTALL_DIR/arpack && \
	sh bootstrap

# delete line 26616d to prevent an error about Eigen, `make check` will be ok
RUN cd ~/arpack-ng-3.8.0 && \
	export LIBRARY_PATH=$LIBRARY_PATH:$INSTALL_DIR/lapack32-so/lib/ && \
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$INSTALL_DIR/lapack32-so/lib/ && \
	sed -i '26616d' ./configure && \
	./configure --prefix=$INSTALL_DIR/arpack && \
	make -j12 && make check -j12 && make install

# ======== GMP ========
RUN cd ~/ && wget -q https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz && \
	lzip -d gmp-6.2.1.tar.lz && \
	tar -xf gmp-6.2.1.tar && cd gmp-6.2.1 && \
	mkdir $INSTALL_DIR/gmp && \
	./configure --prefix=$INSTALL_DIR/gmp && \
	make -j12 && make check -j12 && make install

# ======== MPFR ========
RUN cd ~/ && \
	wget -q https://www.mpfr.org/mpfr-current/mpfr-4.1.0.tar.gz && \
	tar -xzf mpfr-4.1.0.tar.gz && cd mpfr-4.1.0 && \
	mkdir $INSTALL_DIR/mpfr && \
	./configure --prefix=$INSTALL_DIR/mpfr --with-gmp=$INSTALL_DIR/gmp && \
	make -j12 && make check -j12 && make install

# ======== Flint2 ========
RUN cd ~ && wget -q https://github.com/flintlib/flint2/archive/refs/tags/v2.9.0.tar.gz && \
	tar -xzf v2.9.0.tar.gz && cd flint2-2.9.0/ && \
	mkdir $INSTALL_DIR/flint && \
	./configure --prefix=$INSTALL_DIR/flint --with-gmp=$INSTALL_DIR/gmp --with-mpfr=$INSTALL_DIR/mpfr && \
	make -j12 && make check -j12 && make install

# ======== Arb ========
RUN cd ~ && wget -q https://github.com/fredrik-johansson/arb/archive/refs/tags/2.23.0.tar.gz  && \
	tar -xzf 2.23.0.tar.gz && cd arb-2.23.0/ && \
	mkdir $INSTALL_DIR/arb && \
	./configure --prefix=$INSTALL_DIR/arb --with-gmp=$INSTALL_DIR/gmp --with-mpfr=$INSTALL_DIR/mpfr --with-flint=$INSTALL_DIR/flint && \
	make -j12 && make check -j12 && make install && \
	ln -s libarb.so $INSTALL_DIR/arb/lib/libflint-arb.so

# ======== SLISC ========
RUN cd ~/SLISC0 && \
	git pull origin && touch SLISC/*.h && \
	source make/set_path2.sh && \
	make -j12 opt_asan=false && \
	./main.x < input.inp

RUN cd ~/SLISC0 && \
	cp SLISC-long64-quad/*.h SLISC/ && \
	source make/set_path2.sh && \
	make -j12 opt_long32=false opt_quadmath=true opt_asan=false && \
	./main.x < input.inp
