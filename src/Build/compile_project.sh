rm -dv CMake* cmake*
clear
cmake ..
cmake --build . -config runcpp
sudo mv runcpp ../../
