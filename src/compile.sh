#!/bin/sh

# 1) Download and extract camera firmware sources (can be from NX500 even when you want compile app for NX300).
# 2) sudo apt-get install gcc-arm-linux-gnueabihf pkg-config
# 3) Go to directory with firmware sources (one upper than standard-armv7l) and copy intervalometer.c and compile.sh there
# 4) Run this script

export PKG_CONFIG_PATH=./standard-armv7l/usr/lib/pkgconfig/:./standard-armv7l/usr/share/pkgconfig/
export PKG_CONFIG_SYSROOT_DIR=./standard-armv7l/

arm-linux-gnueabihf-gcc -o intervalometer intervalometer.c `pkg-config --cflags --libs ecore elementary` --sysroot=./standard-armv7l/ -Wl,-dynamic-linker,/lib/ld-2.13.so
