#!/bin/bash

# crontab -e
# @reboot /usr/bin/screen -fa -d -m -S arduino $HOME/arduino-http/autorun/autoexec.sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $DIR
cd $DIR
cd ..
while :
do
        echo "Starting arduino listener/pusher"        
        python main.py
        sleep 10
done