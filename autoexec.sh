#!/bin/sh

mkdir -p /dev/pts
mount -t devpts none /dev/pts

#telnetd -l /bin/bash -F > /mnt/mmc/INTVAL/telnetd.log 2>&1 &

stringcontain() {
    [ -z "${2##*$1*}" ] && [ -z "$1" -o -n "$2" ];
}

while true
do
  combo=0

  script -c "xinput test keyboard1" /dev/null | while read line
  do
    if stringcontain "press" "$line"; then
      if stringcontain "91" "$line"; then
        combo=1
        continue
      fi
      if stringcontain "181" "$line"; then
        if [ $combo -eq 1 ]; then
          break
        fi
      fi
      combo=0
    fi
  done

  echo 1 > /sys/devices/platform/leds-gpio/leds/card/brightness
  sleep 0.5
  echo 0 > /sys/devices/platform/leds-gpio/leds/card/brightness

  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/2.png "sh /mnt/mmc/INTVAL/timelapse.sh 2 &" 1 112 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/5.png "sh /mnt/mmc/INTVAL/timelapse.sh 5 &" 1 176 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/10.png "sh /mnt/mmc/INTVAL/timelapse.sh 10 &" 1 240 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/15.png "sh /mnt/mmc/INTVAL/timelapse.sh 15 &" 1 304 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/30.png "sh /mnt/mmc/INTVAL/timelapse.sh 30 &" 1 368 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/45.png "sh /mnt/mmc/INTVAL/timelapse.sh 45 &" 1 432 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/60.png "sh /mnt/mmc/INTVAL/timelapse.sh 60 &" 1 496 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/90.png "sh /mnt/mmc/INTVAL/timelapse.sh 90 &" 1 560 64 64 &
  /mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/X.png "sleep 0.1; killall button_png" 1 624 64 64 &
done
