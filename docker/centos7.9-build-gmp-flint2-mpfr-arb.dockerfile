## run folloing in SLISC0 to build and export library

# sudo docker build -t addiszx/slisc0:centos7.9-build-gmp-flint2-mpfr-arb -f docker/centos7.9-build-gmp-flint2-mpfr-arb.dockerfile . | tee docker-centos7.9-build-gmp-flint2-mpfr-arb.log
# sudo docker run --name centos7.9-build-gmp-flint2-mpfr-arb -itd addiszx/slisc0:centos7.9-build-gmp-flint2-mpfr-arb bash
# sudo docker cp centos7.9-build-gmp-flint2-mpfr-arb:/home/docker/libs/gmp-6.1.2.tar.gz .
# sudo docker cp centos7.9-build-gmp-flint2-mpfr-arb:/home/docker/libs/mpfr-4.1.0.tar.gz .
# sudo docker cp centos7.9-build-gmp-flint2-mpfr-arb:/home/docker/libs/flint2-2.9.0.tar.gz .
# sudo docker cp centos7.9-build-gmp-flint2-mpfr-arb:/home/docker/libs/arb-2.23.0.tar.gz .
# sudo docker rm -f centos7.9-build-gmp-flint2-mpfr-arb

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

# ======== GMP ========
RUN cd ~/ && wget -q https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz && \
	lzip -d gmp-6.2.1.tar.lz && \
	tar -xf gmp-6.2.1.tar && cd gmp-6.2.1 && \
	mkdir $INSTALL_DIR/gmp-6.1.2 && \
	./configure --prefix=$INSTALL_DIR/gmp-6.1.2 && \
	make -j12 && make check -j12 && make install

# ======== MPFR ========
RUN cd ~/ && \
	wget -q https://www.mpfr.org/mpfr-4.1.0/mpfr-4.1.0.tar.gz && \
	tar -xzf mpfr-4.1.0.tar.gz && cd mpfr-4.1.0 && \
	mkdir $INSTALL_DIR/mpfr-4.1.0 && \
	./configure --prefix=$INSTALL_DIR/mpfr-4.1.0 --with-gmp=$INSTALL_DIR/gmp-6.1.2 && \
	make -j12 && make check -j12 && make install

# ======== Flint2 ========
RUN cd ~ && wget -q https://github.com/flintlib/flint2/archive/refs/tags/v2.9.0.tar.gz && \
	tar -xzf v2.9.0.tar.gz && cd flint2-2.9.0/ && \
	mkdir $INSTALL_DIR/flint2-2.9.0 && \
	./configure --prefix=$INSTALL_DIR/flint2-2.9.0 --with-gmp=$INSTALL_DIR/gmp-6.1.2 --with-mpfr=$INSTALL_DIR/mpfr-4.1.0 && \
	make -j12 && make check -j12 && make install

# ======== Arb ========
RUN cd ~ && wget -q https://github.com/fredrik-johansson/arb/archive/refs/tags/2.23.0.tar.gz  && \
	tar -xzf 2.23.0.tar.gz && cd arb-2.23.0/ && \
	mkdir $INSTALL_DIR/arb-2.23.0 && \
	./configure --prefix=$INSTALL_DIR/arb-2.23.0 --with-gmp=$INSTALL_DIR/gmp-6.1.2 --with-mpfr=$INSTALL_DIR/mpfr-4.1.0 --with-flint=$INSTALL_DIR/flint2-2.9.0 && \
	make -j12 && make check -j12 && make install && \
	ln -s libarb.so $INSTALL_DIR/arb-2.23.0/lib/libflint-arb.so

RUN cd $INSTALL_DIR && \
	tar -czf gmp-6.1.2.tar.gz gmp-6.1.2 && rm -r gmp-6.1.2 && \
	tar -czf mpfr-4.1.0.tar.gz mpfr-4.1.0 && rm -r mpfr-4.1.0 && \
	tar -czf flint2-2.9.0.tar.gz flint2-2.9.0 && rm -r flint2-2.9.0 && \
	tar -czf arb-2.23.0.tar.gz arb-2.23.0 && rm -r arb-2.23.0
