FROM ubuntu:22.04 AS base

RUN apt-get update

RUN apt-get install -yq tzdata

RUN  ln -fs /usr/share/zoneinfo/Europe/Warsaw /etc/localtime

RUN apt-get -y install build-essential \
    git wget gpg \
    cmake

# Install Libzmq
RUN wget -qO- "https://github.com/zeromq/libzmq/releases/download/v4.3.4/zeromq-4.3.4.tar.gz" | \
    tar -xz && \
    cd zeromq-4.3.4 && \
    ./configure && \
    make && \
    make install

RUN wget -qO- "https://github.com/zeromq/cppzmq/archive/refs/tags/v4.9.0.tar.gz" | \
    tar -xz && \
    cd cppzmq-4.9.0 && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j4 install

RUN apt-get install -y nlohmann-json3-dev libfmt-dev

RUN apt-get install -y gdb

WORKDIR /workspace
COPY . .

RUN mkdir build && cd build && cmake .. && make
ENTRYPOINT /workspace/build/worker