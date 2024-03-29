# To build docker image, use `sudo docker build -t slisc0 -f Dockerfile_XXX .`
# To run test, use `sudo docker run slisc0`
# To open a bash, use `sudo docker run -it slisc0 bash`
# more docker commands https://wuli.wiki/online/Docker.html

FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y vim git make g++ gdb gfortran libarpack++2-dev liblapacke-dev libsqlite3-dev libgmp-dev libflint-arb-dev libflint-dev libgsl-dev libboost-filesystem-dev && \
	apt purge -y libopenblas*

# set your timezone
RUN apt install -y tzdata
ENV TZ America/Chicago
RUN echo "${TZ}" > /etc/timezone \
  && ln -sf /usr/share/zoneinfo/America/Chicago /etc/localtime \
  && dpkg-reconfigure -f noninteractive tzdata

RUN	cd /root/ && \
	git clone https://github.com/MacroUniverse/SLISC --depth 1 && \
	git clone https://github.com/MacroUniverse/Arpack_test --depth 1 && \
	git clone https://github.com/MacroUniverse/EigenTest --depth 1 && \
	git clone https://github.com/MacroUniverse/boost-headers --depth 1

RUN	cd /root/SLISC && \
	touch SLISC/*.h && \
	make -j`getconf _NPROCESSORS_ONLN`

RUN echo "#! /bin/bash" > /test.sh && \
	echo "cd /root/SLISC" >> /test.sh && \
	echo "./main.x < input.inp" >> /test.sh && \
	chmod +x /test.sh

CMD ["/test.sh"]
