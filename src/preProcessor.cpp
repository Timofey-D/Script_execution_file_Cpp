#include <iostream>
#include "preProcessor.h"
#include <cstring>
#include <fstream>
#include <algorithm>
#define SIZE_OF_FLAGS 5
#define SIZE_OF_NAME 64


PreProcessor::PreProcessor(const char * source_code, const char * flags)
{
    this->execution_file = new char[SIZE_OF_NAME];
    getFilename(source_code, this->execution_file);
    
    if (flags != 0)
    {
        executionFlags(flags);
    }
}


void PreProcessor::getFilename(const char * source_code, char * target_file)
{
    char * filename = new char[SIZE_OF_NAME];
    for (int i = 0; source_code[i] != '.'; i++)
    {
        filename[i] = source_code[i];
    }
    strcpy(target_file, filename);
    delete[] filename;
}


void PreProcessor::createExeFile(const bool & new_file, const bool & extension)
{
    int ID = 1;
    char * temp_filename = new char[SIZE_OF_NAME];
    strcpy(temp_filename, this->execution_file);

    // if extension equalls 0, then it needs to add extension
    if (!extension)
    {
        strcat(temp_filename, ".exe\0"); 
    }

    // if this statement equalls 0 and 0, then 
    if (!checkFileExe(temp_filename) || !new_file)
    {
        delete[] this->execution_file;
        this->execution_file = new char[SIZE_OF_NAME];
        strcpy(this->execution_file, temp_filename);
        delete[] temp_filename;
        return;
    }

    do 
    {
        delete[] temp_filename;

        temp_filename = new char[SIZE_OF_NAME];
        strcpy(temp_filename, this->execution_file);
        strcat(temp_filename, "_");
        strcat(temp_filename, std::to_string(ID++).c_str());

        if (!extension)
        {
            strcat(temp_filename, ".exe"); 
        }
    } while(checkFileExe(temp_filename) || !new_file);
    
    delete[] this->execution_file;
    
    this->execution_file = new char[SIZE_OF_NAME];
    strcpy(this->execution_file, temp_filename);

    delete[] temp_filename;
}
