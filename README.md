# Run script for C++
The script was wrote for comfortable work with C++ files.
The script is based on compilator g++ and version C++ 17.

if you work a lot of time in command line, then this script is comfortable.
Script contains several commands:
1) run filename.cpp -e ==> to compile a source_file and to execute right now;
2) run filename.cpp -p ==> to compile a source_file and print an execution file name;
3) run filename.cpp -n ==> to compile a source_code and to create another execution file without removing previous execution file.
4) run filename.cpp -d ==> to compile a source_code and to delete an execution file at once after executing.
5) run filename.cpp -w ==> to compile a source code to execution file without extenstion.
All these command flags can be used together.

The script allows to choose certain command g++:
There are following commands:
1) -0 (g++ source -o execution)
2) -1 (g++ -Wall source -o execution)
3) -2 (g++ -Wall -pedantic source -o execution)
4) -3 (g++ -Wall -pedantic -std=c++17 source -o execution)

There is necessary to check that you have a cmake via terminal using the following command:
cmake --version (The version must be at least 3.10)

In order to run this script on your computer, you have to put it in root directory.
You have to do the following action:
1) echo $PATH (for example /usr/local/bin)
2) cd /usr/local/bin
3) git clone https://github.com/Timofey-D/run_script.git
4) cd run_script
5) ./install_script.sh (if it happens some error, you can add "sudo" before command)
6) it must appear an execution file on the current directory, which called "runcpp"
7) mv runcpp /usr/local/bin

A message will be printed about succesful finished installing. 

Execution file called "runcpp" will be in previous directory.

After that, everything has to work!
