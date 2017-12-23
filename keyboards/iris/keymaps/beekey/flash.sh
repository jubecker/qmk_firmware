#!/bin/sh
avrdude -p atmega32u4 -c avr109 -P /dev/tty.usbmodem1411 -U flash:w:.build/iris_rev2_beekey.hex
