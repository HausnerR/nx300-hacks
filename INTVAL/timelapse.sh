#!/bin/sh

sleep 0.1
killall button_png

st lcd set 4

if [ $1 -eq 0 ]
then
  st key push s1
  st key push s2
else
  while :
  do
    st key push s1
    st key click s2
    st key release s1
    sleep $1
  done
fi
