#!/bin/bash

gcc -Wall -Wextra -pedantic -o compiled ./program1.c

./compiled

echo -ne '\007'


