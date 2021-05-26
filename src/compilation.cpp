#include <iostream>
#include <cstring>
#include <cstdio>
#include "compilation.h"

Compilation::Compilation(const char * source, const char * execution, const int & flag)
{
    char * command = new char[64];

    auto setting = this->compile_command.find(flag);
    strcpy(command, setting->second);

    strcat(command, source);
    strcat(command, " -o ");

    strcat(command, execution);

    std::system(command);

    delete[] command;
}
