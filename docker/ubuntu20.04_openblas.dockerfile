# To build docker image, use `sudo docker build -t slisc0 -f Dockerfile_XXX .`
# To run test, use `sudo docker run slisc0`
# To open a bash, use `sudo docker run -it slisc0 bash`
# more docker commands https://wuli.wiki/online/Docker.html

FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && \
	apt -y upgrade && \
	apt install -y vim git make g++ gdb gfortran wget automake

# set your timezone
RUN apt install -y tzdata
ENV TZ America/Chicago
RUN echo "${TZ}" > /etc/timezone \
  && ln -sf /usr/share/zoneinfo/America/Chicago /etc/localtime \
  && dpkg-reconfigure -f noninteractive tzdata

# set number of threads for compilation
ARG NCPU=8

RUN cd /root/ && \
	wget -q https://github.com/xianyi/OpenBLAS/releases/download/v0.3.21/OpenBLAS-0.3.21.tar.gz && \
	tar -xzf OpenBLAS-0.3.21.tar.gz

RUN cd /root/OpenBLAS-0.3.21/ && \
	make USE_THREAD=0 -j$NCPU  && \
	make install

RUN	cd /root/ && \
	git clone --depth 1 https://github.com/MacroUniverse/SLISC0 && \
	touch SLISC0/SLISC/*.h

RUN cd /root/SLISC0 && \
	make -j$NCPU opt_lapack=openblas opt_boost=false opt_gsl=false opt_eigen=false opt_arb=false opt_arpack=false opt_sqlite=false && \
	mv main.x main32.x

RUN cd /root/SLISC0 && \
	cp SLISC-long64-quad/*.h SLISC/ && \
	rm -f *.o *.x && \
	make -j$NCPU opt_lapack=openblas opt_boost=false opt_gsl=false opt_eigen=false opt_arb=false opt_arpack=false opt_sqlite=false

RUN echo "source /root/SLISC0/make/ld_path_append.sh /opt/OpenBLAS/lib" >> ~/.bashrc

RUN echo "#! /bin/bash" > /test.sh && \
	echo "source /root/SLISC0/make/ld_path_append.sh /opt/OpenBLAS/lib" >> /test.sh && \
	echo "cd /root/SLISC0" >> /test.sh && \
	echo "./main32.x < input.inp" >> /test.sh && \
	echo "printf '\n\n\n\n\n\n'" >> /test.sh && \
	echo "./main.x < input.inp" >> /test.sh && \
	chmod +x /test.sh

CMD ["/test.sh"]
