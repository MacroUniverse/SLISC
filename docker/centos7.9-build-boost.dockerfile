## run folloing in SLISC to build and export library

# sudo docker build -t addiszx/slisc0:centos7.9-build-boost -f docker/centos7.9-build-boost.dockerfile . | tee docker-centos7.9-build-boost.log
# sudo docker run --name centos7.9-build-boost -itd addiszx/slisc0:centos7.9-build-boost bash
# sudo docker cp centos7.9-build-boost:/home/docker/libs/boost-1.80.0.tar.gz .
# sudo docker rm -f centos7.9-build-boost

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

# ======== Boost ========
# ./bootstrap.sh ... --with-libraries=filesystem to select sub lib
# ./b2 install -j`getconf _NPROCESSORS_ONLN` will return exit code 1 since there are missing dependencies
#      for a few components, which will be skipped.
RUN cd ~ && \
	wget -q https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/boost_1_80_0.tar.gz
	
RUN cd ~ && \
	tar -xzf boost_1_80_0.tar.gz && cd boost_1_80_0 && \
	mkdir $INSTALL_DIR/boost-1.80.0 && \
	./bootstrap.sh --prefix=$INSTALL_DIR/boost-1.80.0 || \
	./b2 install -j`getconf _NPROCESSORS_ONLN`

RUN cd $INSTALL_DIR && \
	tar -czf boost-1.80.0.tar.gz boost-1.80.0 && \
	rm -r boost-1.80.0
