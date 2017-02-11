#!/bin/sh

if [ $(cat /sys/devices/platform/jack/charger1_online) == "1" ]
then
    /mnt/mmc/CHARGENSHOOT/chargenshoot &
fi
