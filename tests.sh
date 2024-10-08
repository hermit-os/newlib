#!/bin/bash

OS_NAME=$1
OS_VERSION=$2

if [ "$OS_NAME" = "centos" ]; then

# Clean the yum cache
yum -y clean all
yum -y clean expire-cache

# First, install all the needed packages.
yum install -y wget gettext flex bison binutils gcc gcc-c++ texinfo kernel-headers rpm-build kernel-devel boost-devel cmake git tar gzip make autotools

wget http://checkinstall.izto.org/files/source/checkinstall-1.6.2.tar.gz
tar xzvf checkinstall-1.6.2.tar.gz
cd checkinstall-1.6.2
./configure
make
make install
cd ..
rm -rf checkinstall*

mkdir -p build
cd build
../configure --target=x86_64-hermit --prefix=/opt/hermit --disable-shared --disable-nls --disable-gdb --disable-libdecnumber --disable-readline --disable-sim --disable-libssp --enable-tls --disable-multilib
make
checkinstall -R -y --exclude=build --pkggroup=main --maintainer=stefan@eonerc.rwth-aachen.de --pkgsource=https://hermitcore.org --pkgname=newlib-hermit --pkgversion=2.30.51 --pkglicense=GPL2 make install

else

export DEBIAN_FRONTEND="noninteractive"

apt-get -qq update || exit 1
apt-get install -y --no-install-recommends checkinstall gcc libc-dev || exit 1

echo "deb [trusted=yes] http://dl.bintray.com/hermitcore/ubuntu bionic main" >> /etc/apt/sources.list
apt-get update || exit 1
apt-get install -y --allow-unauthenticated binutils-hermit gcc-hermit-bootstrap || exit 1
export PATH=/opt/hermit/bin:$PATH

export CROSSCOMPREFIX=x86_64-hermit
export STACKPROT=-fno-stack-protector
export CFLAGS_FOR_TARGET="-m64 -mtls-direct-seg-refs -O3 -ftree-vectorize"
export FCFLAGS_FOR_TARGET="-m64 -mtls-direct-seg-refs -O3 -ftree-vectorize"
export FFLAGS_FOR_TARGET="-m64 -mtls-direct-seg-refs -O3 -ftree-vectorize"
export CXXFLAGS_FOR_TARGET="-m64 -mtls-direct-seg-refs -O3 -ftree-vectorize"

mkdir -p build
cd build
../configure --target=x86_64-hermit --disable-shared --disable-multilib --disable-multilib --enable-lto --enable-newlib-hw-fp --enable-newlib-io-c99-formats --enable-newlib-multithread --disable-multilib --prefix=/opt/hermit || exit 1
make -j2 || exit 1
checkinstall -D -y --exclude=build --pkggroup=main --maintainer=stefan@eonerc.rwth-aachen.de --pkgsource=https://hermitcore.org --pkgname=newlib-hermit-rs --pkgversion=3.0.1 --conflicts=newlib-hermit --pkglicense=BSD-3-Clause make install || exit 1

cd ..
mkdir -p tmp
dpkg-deb -R build/newlib-hermit-rs_3.0.1-1_amd64.deb tmp
rm -f build/newlib-hermit-rs_3.0.1-1_amd64.deb

fi
