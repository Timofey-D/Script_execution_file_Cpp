rm -v CMakeCache.txt
clear
cmake ..
cmake --build . -config runcpp
sudo mv runcpp ../../
