FROM centos:7.9.2009
ARG MPLAPACK_VER="2.0.1"

RUN yum install -y https://repo.ius.io/ius-release-el7.rpm
RUN yum install -y centos-release-scl
RUN yum install -y devtoolset-9
SHELL [ "scl", "enable", "devtoolset-9" ]
RUN yum install -y gcc gcc-c++ gcc-gfortran make automake libtool gnuplot
RUN yum install -y python3
RUN yum install -y sudo which patch bzip2 git wget time parallel
RUN yum install -y emacs

ARG DOCKER_UID=1000
ARG DOCKER_USER=docker
ARG DOCKER_PASSWORD=docker
RUN useradd -u $DOCKER_UID -m $DOCKER_USER --shell /bin/bash -G wheel,root && \
    echo "$DOCKER_USER:$DOCKER_PASSWD" | chpasswd && \
    echo "$DOCKER_USER ALL=(ALL) ALL" >> /etc/sudoers && \
    echo "$DOCKER_USER ALL=NOPASSWD: ALL" >> /etc/sudoers

USER ${DOCKER_USER}
RUN cd /home/$DOCKER_USER && echo "cd /home/$DOCKER_USER" >> .bashrc
RUN cd /home/$DOCKER_USER && wget https://github.com/nakatamaho/mplapack/releases/download/v${MPLAPACK_VER}/mplapack-${MPLAPACK_VER}.tar.xz
RUN cd /home/$DOCKER_USER && tar xvfJ mplapack-${MPLAPACK_VER}.tar.xz
RUN cd /home/$DOCKER_USER/mplapack-${MPLAPACK_VER}
RUN gcc --version && g++ --version && gfortran --version
ARG CXX="/opt/rh/devtoolset-9/root/usr/bin/g++"
ARG CC="/opt/rh/devtoolset-9/root/usr/bin/gcc"
ARG FC="/opt/rh/devtoolset-9/root/usr/bin/gfortran"
RUN cd /home/$DOCKER_USER/mplapack-${MPLAPACK_VER} && ./configure --prefix=$HOME/MPLAPACK --enable-gmp=yes --enable-mpfr=yes --enable-_Float128=yes --e\nable-qd=yes --enable-dd=yes --enable-double=yes --enable-_Float64x=yes --enable-test=yes --enable-benchmark=yes
RUN cd /home/$DOCKER_USER/mplapack-${MPLAPACK_VER} && make -j`getconf _NPROCESSORS_ONLN`
RUN cd /home/$DOCKER_USER/mplapack-${MPLAPACK_VER} && make install
