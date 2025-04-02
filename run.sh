#!/bin/bash

# Author: Andy Yo
# License: MIT License
# Description: 
#   This script automates the process of compiling, inserting, and removing
#   the "simple" kernel module. It is useful for testing and debugging kernel
#   module behavior and helps verify the module's effect on the kernel logs.

sudo dmesg -C
echo "Clearing old kernel logs"
echo

echo "Compiling Kernel Module"
make
echo

echo "Inserting simple.ko"
sudo insmod simple.ko
echo

echo "Checking dmesg output:"
sudo dmesg
echo

echo "Removing module simple.ko"
sudo rmmod simple
echo

echo "Checking dmesg output after removal:"
sudo dmesg
echo
