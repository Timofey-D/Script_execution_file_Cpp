sudo rm -dv CMake* cmake*
clear
cmake ..
sudo cmake --build . --config
sudo mv runcpp ../../
