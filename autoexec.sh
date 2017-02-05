#!/bin/sh

mkdir -p /dev/pts
mount -t devpts none /dev/pts

#telnetd -l /bin/bash -F > /mnt/mmc/INTVAL/telnetd.log 2>&1 &

/mnt/mmc/INTVAL/intval.sh &
