#!/bin/sh

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

  /mnt/mmc/INTVAL/intervalometer &
done
