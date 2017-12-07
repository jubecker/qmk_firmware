#!/bin/sh

sudo dfu-programmer atmega32u4 erase --debug 5
sudo dfu-programmer atmega32u4 flash ../../.build/jd45_beekey.hex --debug 5
sudo dfu-programmer atmega32u4 start
