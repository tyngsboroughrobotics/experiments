#!/bin/bash -e

USER="pi@raspberrypi.local"
PASSWORD="wallaby"
PROJECT_PATH="/home/root/Documents/KISS/KIPR/botball-2022"

echo -n "Installing..."

zip -rq game.zip . -x .\*

sshpass -p $PASSWORD ssh $USER "
    sudo rm -rf \"$PROJECT_PATH\"
    sudo mkdir -p \"$PROJECT_PATH\"
    sudo chmod -R a+rwX \"$PROJECT_PATH\"
"

sshpass -p $PASSWORD scp ./game.zip $USER:$PROJECT_PATH

rm game.zip

sshpass -p $PASSWORD ssh $USER "
    cd $PROJECT_PATH
    unzip -q game.zip -d .
    rm game.zip
    mkdir -p bin
    gcc -o bin/botball_user_program -lwallaby -lpthread -lm -Iinclude src/*.c
"

echo " done"

sshpass -p $PASSWORD ssh $USER "$PROJECT_PATH/bin/botball_user_program"
