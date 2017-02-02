#!/bin/sh

mkdir -p /dev/pts
mount -t devpts none /dev/pts

#telnetd -l /bin/bash -F > /mnt/mmc/INTVAL/telnetd.log 2>&1 &

stringcontain() {
    [ -z "${2##*$1*}" ] && [ -z "$1" -o -n "$2" ];
}

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

/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/2.png "sh /mnt/mmc/INTVAL/timelapse.sh 2 &" 1 144 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/5.png "sh /mnt/mmc/INTVAL/timelapse.sh 5 &" 1 208 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/10.png "sh /mnt/mmc/INTVAL/timelapse.sh 10 &" 1 272 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/15.png "sh /mnt/mmc/INTVAL/timelapse.sh 15 &" 1 336 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/30.png "sh /mnt/mmc/INTVAL/timelapse.sh 30 &" 1 400 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/45.png "sh /mnt/mmc/INTVAL/timelapse.sh 45 &" 1 464 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/60.png "sh /mnt/mmc/INTVAL/timelapse.sh 60 &" 1 528 64 64 &
/mnt/mmc/INTVAL/button_png /mnt/mmc/INTVAL/90.png "sh /mnt/mmc/INTVAL/timelapse.sh 90 &" 1 592 64 64 &
