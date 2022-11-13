FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y vim git make g++ gdb

# set your timezone
RUN apt install -y tzdata
ENV TZ America/Chicago
RUN echo "${TZ}" > /etc/timezone \
  && ln -sf /usr/share/zoneinfo/America/Chicago /etc/localtime \
  && dpkg-reconfigure -f noninteractive tzdata

COPY l_BaseKit_*.sh /root/
COPY l_HPCKit_*.sh /root/

# check components
# sh ./l_???.sh  -a --list-components

RUN cd /root/ && \
	sh ./l_BaseKit_p_*.sh -a --silent --action install --eula accept --components intel.oneapi.lin.mkl.devel

RUN cd /root/ && rm -rf l_BaseKit_p_*

RUN cd /root/ && \
	sh ./l_HPCKit_p_*.sh -a --silent --action install --eula accept --components intel.oneapi.lin.dpcpp-cpp-compiler-pro:intel.oneapi.lin.mpi.devel

RUN cd /root/ && rm -rf l_HPCKit_p_*

# only effective for bash section
RUN echo "source /opt/intel/oneapi/setvars.sh" >> ~/.bashrc

RUN cd /root/ && git clone https://github.com/MacroUniverse/SLISC0 --depth 1 && \
	cd /root/SLISC0 && touch SLISC/*.h

RUN cd /root/SLISC0 && . /opt/intel/oneapi/setvars.sh && \
	git pull && make -j12 opt_lapack=mkl opt_boost=false opt_gsl=false opt_eigen=false opt_arb=false opt_arpack=false opt_sqlite=false && \
	./main.x < input.inp
