#!/bin/bash
set -e
NDK=$HOME/apps/android-ndk-r10d # TODO
TOOLCHAIN=$PWD/toolchain/bin
PREFIX=arm-linux-androideabi
THISDIR=$PWD

if [ ! -e toolchain ]; then
    $NDK/build/tools/make-standalone-toolchain.sh --platform=android-21 --install-dir=toolchain --arch=arm
fi

cd ../../../..

if [ "$1" = "clean" ]; then
    PATH=$TOOLCHAIN:$THISDIR:$PATH make clean
fi

if [ ! -e Makefile ]; then
# from https://github.com/kost/nmap-android/blob/master/android/Makefile
PATH=$TOOLCHAIN:$THISDIR:$PATH \
    LUA_CFLAGS="-DLUA_USE_POSIX" LDFLAGS="-static" ac_cv_linux_vers=2 \
    CC=$PREFIX-gcc CXX=$PREFIX-g++ LD=$PREFIX-ld RANLIB=$PREFIX-ranlib \
    AR=$PREFIX-ar STRIP=$PREFIX-strip \
    ./configure --host=arm-linux --without-zenmap --with-liblua=included \
    --with-libpcap=internal --with-pcap=linux --enable-static
fi

PATH=$TOOLCHAIN:$THISDIR:$PATH \
    make #-j$(getconf _NPROCESSORS_ONLN)
