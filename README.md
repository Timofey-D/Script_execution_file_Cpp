# Script_execution_file_Cpp
The script was wrote for comfortable work with file C++.
The script is based on compilator g++ and version C++ 17.

if you work a lot of time in command line, then this script is comfortable.
Script contains several commands:
1) run filename.cpp -e ==> to compile a source_file and to execute right now;
2) run filename.cpp -p ==> to compile a source_file and print an execution file name;
3) run filename.cpp -n ==> to compile a source_code and to create another execution file without removing previous execution file.
4) run filename.cpp -d ==> to compile a source_code and to delete an execution file at once after executing.

All these command flags can be used together.

In order to run this script on your computer, you have to put it in root directory.
You have to do the following action:
1) echo $PATH = usr/local/bin (for example)
2) cd usr/local/bin ==> To put this script and compile it
3) g++ -Wall -pedantic -std=c++17 run.cpp -o run

After that, everything has to work!
