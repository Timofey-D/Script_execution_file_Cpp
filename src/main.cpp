#include <iostream>
#include <cstdlib>
#include "main.h"
#include "input.h"
#include "preProcessor.h"
#include "compilation.h"
#include "postProcessor.h"

int main(int argc, const char * argv[])
{
    // To add a the end of each char pointers specified character, which points to the end of string
    for (int i = 1; i < argc; i++)
    {
        argv[i] += '\0';
    }
    
    // To create a variable, which will get right input
    Input right_input;

    try
    {
        Input input(argv, argc);
        right_input = input;
    } catch (std::exception & error)
    {
        std::cout << error.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    char * source = right_input.getSourceCode();
    char * flags = right_input.getFileFlags();
    int coflag = right_input.getCompileFlag();

    PreProcessor preparing_file(source, flags);
    char * execution = preparing_file.getExecutionFile();

    Compilation compiler(source, execution, coflag);

    PostProcessor running(execution, flags); 

    return 0;
}

