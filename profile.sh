#!/bin/bash

current_profile=$(powerprofilesctl get)

case "$current_profile" in
    power-saver)
        powerprofilesctl set balanced
        ;;
    balanced)
        powerprofilesctl set performance
        ;;
    performance)
        powerprofilesctl set power-saver
        ;;
esac