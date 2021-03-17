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

In order to run this script on your computer, you have to put it in root directory.
You have to do the following action:
1) echo $PATH (for example /url/local/bin)
2) cd /usr/local/bin
3) git clone https://github.com/Timofey-D/run_script.git
4) cd /usr/local/bin/run_script
5) ./install.sh
6) cd ../

A message will be printed about succesful finished installing. 

Execution file called "run" will be in previous directory.

After that, everything has to work!
