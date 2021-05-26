rm -v CMakeCache.txt
clear
cmake ..
cmake --build . -config runcpp
chmod +x runcpp
sudo mv runcpp ../../
