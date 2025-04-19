#!/bin/bash

# Author: Andy Yo
# License: MIT License
# Description: 
#   This script automates the process of compiling, inserting, and removing
#   the "hello" kernel module. It is useful for testing and debugging kernel
#   module behavior.

MODULE_NAME="hello"
MODULE_FILE="$MODULE_NAME.ko"
PROC_FILE="/proc/$MODULE_NAME"

echo "Cleaning old build artifacts..."
make clean > /dev/null 2>&1
echo

echo "Building kernel module..."
make || { echo "Build failed."; exit 1; }
echo

echo "Removing old module (if loaded)..."
sudo rmmod $MODULE_NAME 2>/dev/null
echo

echo "Inserting module..."
sudo insmod $MODULE_FILE || { echo "Insert failed."; exit 1; }
echo

echo "Verifying module is loaded..."
if lsmod | grep -q "^$MODULE_NAME"; then
    echo "Module                  Size  Used by"
    lsmod | grep "^$MODULE_NAME"
else
    echo "Module '$MODULE_NAME' not found in lsmod."
fi
echo

echo "Reading from $PROC_FILE:"
cat $PROC_FILE
echo
