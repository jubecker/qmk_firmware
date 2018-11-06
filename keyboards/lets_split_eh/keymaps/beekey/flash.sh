#!/bin/bash

sudo dfu-programmer atmega32u4 erase --force
sudo dfu-programmer atmega32u4 flash --debug 5 $1
sudo dfu-programmer atmega32u4 reset
