## run folloing in SLISC to build and export library

# sudo docker build -t addiszx/slisc0:centos7.9-portable -f docker/centos7.9-portable.dockerfile . | tee docker-centos7.9-portable.log

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

RUN	cd ~/ && \
	git clone https://github.com/MacroUniverse/SLISC --depth 4 && \
	git clone https://github.com/MacroUniverse/SLISC-libs-x64-centos7.9.2009 --depth 1

# copy prebuilt libraries
ARG INSTALL_DIR=/home/$DOCKER_USER/SLISC-libs-x64-centos7.9.2009

# set number of threads for compilation
ARG NCPU=8

# ===================================
# address sanitizer is not available
# some gcc static libs are also not available (e.g. -lm -lpthread)
# ===================================

# ======== SLISC 32-bit dynamic no-quadmath ========
RUN cd ~/SLISC-libs-x64-centos7.9.2009 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && touch SLISC/*.h && \
	rm -f *.o && make opt_asan=false -j$NCPU && \
	./main.x < input.inp

# ======== SLISC 64-bit dynamic quadmath ========
RUN cd ~/SLISC-libs-x64-centos7.9.2009 && source setup.sh && \
	cd ~/SLISC && \
	git pull origin && git reset --hard && cp SLISC-long64-quad/*.h SLISC/ && \
	rm -f *.o && make opt_asan=false opt_long32=false opt_quadmath=true opt_no__Float128=true -j$NCPU && \
	./main.x < input.inp
