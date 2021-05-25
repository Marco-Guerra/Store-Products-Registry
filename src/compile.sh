#!/bin/sh

gcc main.c controllers/*.c models/*.c utilities/*.c -o ../build/main.x -lm

exit 0