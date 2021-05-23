#!/bin/sh

gcc main.c controllers/*.c models/*.c tree/*.c views/*.c utilities/*.c -o ../build/main.x -lm

exit 0