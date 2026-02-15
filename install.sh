#!/bin/bash

# Install script for GINIT, PR's for efficency are GREATLY appreciated as I have around 0.01 IQ with bash.

gcc main.c ginitcompiler.c returnnewtext.c -o ginit
chmod +x ginit

mkdir -p ~/.local/bin
cp ginit ~/.local/bin/

mkdir -p ~/.ginit/
mkdir -p ~/.ginit/initcache/
mkdir -p ~/.ginit/templates/

