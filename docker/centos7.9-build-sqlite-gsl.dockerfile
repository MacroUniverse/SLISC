## run folloing in SLISC to build and export library

# sudo docker build -t addiszx/slisc0:centos7.9-build-sqlite-boost-gsl -f docker/centos7.9-build-sqlite-boost-gsl.dockerfile . | tee docker-centos7.9-build-sqlite-boost-gsl.log
# sudo docker run --name centos7.9-build-sqlite-boost-gsl -itd addiszx/slisc0:centos7.9-build-sqlite-boost-gsl bash
# sudo docker cp centos7.9-build-sqlite-boost-gsl:/home/docker/libs/sqlite-3.40.0.tar.gz .
# sudo docker cp centos7.9-build-sqlite-boost-gsl:/home/docker/libs/boost-1.80.0.tar.gz .
# sudo docker cp centos7.9-build-sqlite-boost-gsl:/home/docker/libs/gsl-2.7.1.tar.gz .
# sudo docker rm -f centos7.9-build-sqlite-boost-gsl

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
	mkdir $INSTALL_DIR/gsl-2.7.1 && \
	./configure --prefix=$INSTALL_DIR/gsl-2.7.1 && \
	make -j$NCPU && make check -j$NCPU && make install

RUN cd $INSTALL_DIR && \
	tar -czf sqlite-3.40.0.tar.gz sqlite-3.40.0 && rm -r sqlite-3.40.0 && \
	tar -czf boost-1.80.0.tar.gz boost-1.80.0 && rm -r boost-1.80.0 && \
	tar -czf gsl-2.7.1.tar.gz gsl-2.7.1 && rm -r gsl-2.7.1
