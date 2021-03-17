#!/bin/bash
echo "Starting compilation..."
SOURCE=$(echo run.cpp)
SUCCESS=$(echo $?)
g++ -Wall -pedantic -std=c++17 ${SOURCE} -o run
if [ $SUCCESS -eq 0 ]; 
then
        EXECUTION_FILE=$(echo run)
        mv ${EXECUTION_FILE} ../ 
        echo "Script was compiled!"
else
        echo "Something went wrong!\nExit status: $?"
fi
FIN=$(echo $?)
if [ $FIN -eq 0 ];
then
        echo "Installing was finished succesful!"
else
        echo "Exit status: $?"
fi
