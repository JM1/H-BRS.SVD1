# H-BRS.SVD1
[![Build Status](https://travis-ci.org/JM1/H-BRS.SVD1.svg?branch=master)](https://travis-ci.org/JM1/H-BRS.SVD1)

# How to build this code using Docker

```sh
# install Docker CE for Debian or derivatives
# please follow guide at https://docs.docker.com/install/linux/docker-ce/debian/

# docker version 18.06.0-ce or later is recommended
docker --version

# get dockerctl
git clone --depth 1 https://gist.github.com/ab8c3beea108ea14a6b8955050f36357.git
export PATH="$PWD/ab8c3beea108ea14a6b8955050f36357/:$PATH"

docker pull jm1337/debian-testing-cpp-dev

# log into docker container
dockerctl run --login --systemd -- jm1337/debian-testing-cpp-dev

# an alternative, more sophisticated environment for development which 
#  - enables gpu acceleration within container
#  - mounts your home directory into the container
#  - enables 'seccomp=unconfined' which is required for gdb debugging
dockerctl run --login --x11 --gpu --systemd --                    \
  -v "$HOME":/tmp/VOLUMES/home:rw -e DEVIL_HOME=/tmp/VOLUMES/home \
  --security-opt seccomp=unconfined                               \
  jm1337/debian-testing-cpp-dev

# the following commands are executed within the docker container

# fetch and compile H-BRS.SVD1
git clone --depth 1 https://github.com/JM1/H-BRS.SVD1.git
cd H-BRS.SVD1
mkdir build && cd build/
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  -DHBRS_MPL_ENABLE_TESTS=ON \
  ..

make -j$(nproc)
ctest --output-on-failure
```

For more examples how to build and test code see [`.travis.yml`](https://github.com/JM1/H-BRS.SVD1/blob/master/.travis.yml).
