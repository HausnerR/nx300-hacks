# nx300-hacks
Samsung NX300 camera hacks

## Installation:
Put content of **dist** folder on sdcard root directory.

## How to charge camera and shoot photos simultaneously:
Connect turned off camera to power source (red led should light up), then turn on camera. Wait a second and camera should ask you to turn it off. Do it, after that your camera should be charged and powered on at the same time.

## How to use intervalometer:
Click trash button and then click +/- button. After 2-3 seconds you should see window for setting interval length. Use screen keyboard or up/down buttons for adjust. When you click OK, camera turn off display and start capturing photos until off.

## SSH & FTP:
**autoexec.sh** have commented two Additional lines. One for FTP server that serves sdcard data with read/write permissions, and one for telnet server.

## Bugs:
1. Any WIFI apps in charge'n'shoot mod enabled causes camera turn off,
2. Photos preview doesn't work in charge'n'shoot mode,
3. Intervalometer on first run sometimes don't display keyboard. Click somewhere else on screen and then again on intervalometer window to get virtual keys, or just use keypad buttons.
