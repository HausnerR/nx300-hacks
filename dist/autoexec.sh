#!/bin/sh

mkdir -p /dev/pts
mount -t devpts none /dev/pts

#SSH
#telnetd -l /bin/bash -F &

#FTP
#tcpsvd -u root -vE 0.0.0.0 21 ftpd -w  /mnt/mmc &

#Charge'n'shoot
/mnt/mmc/CHARGENSHOOT/chargenshoot.sh &

#Intervalometer
/mnt/mmc/INTVAL/intval.sh &
