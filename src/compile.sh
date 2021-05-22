#!/bin/sh

gcc main.c controllers/*.c models/*.c tree/*.c views/*.c -o ../build/main.x -lm

exit 0