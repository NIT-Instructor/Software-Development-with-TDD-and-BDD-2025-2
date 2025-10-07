# Dockerfile with with CMake, Google Test, Valgrind and C++ build tools

FROM ubuntu:latest

# Install Ubuntu packages, as each RUN commits the layer to image, need to
# chain commands and clean up in the end to keep the image small
RUN apt-get update && \
        apt-get install -y --no-install-recommends \
        git \
        build-essential \
        # clang-8 clang-format-8 \
        pkg-config \
        cmake \
        # libgtest-dev \
        # libgmock-dev \
        valgrind \
        gdb \
        cppcheck \
        zip \
        unzip \
        ca-certificates \
        lcov \
        libpcsclite-dev && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists

RUN apt-get update && \
        apt-get install -y openssh-client && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

# Clone the GTest and GMock repositories
RUN git clone https://github.com/google/googletest.git

# Build GTest and GMock using CMake
RUN cd googletest && \
        mkdir build  && \
        cd build && \
        cmake .. && \
        cmake --build . --target install