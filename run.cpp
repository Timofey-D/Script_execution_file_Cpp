#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "run.h"
#include <cstring>

#define MAX_SYM 16
#define MAX_LENGTH_FILE_NAME 255
#define COMMAND_LENGTH 255

const char * commands = "epndw\0";


int main(int argc, const char * argv[])
{
	/*
	 * The script helps to save time and allows to compile and run C++ program via one command.
	 * Command looks like "run filename -flag"
	 * run filename => to compile a program
	 * run filename -e => to run a pragram right now after compilation
	 * run filename -p => to print a name of execution file
	 * run filename -n => to create new execution file without removing previous execution file 
	 * run filename -d => to compile a file and execute it and delete after execution
         * run filename -w => to compile a file without extension ".exe".
        */
	
	// To check whether there are some flags
 	bool thereAreFlags = argc == 3 && argv[2][0] == '-'; 
	// The array of flags
	char * flags = nullptr;
	// The source_code of a program
	char * source_code = new char[MAX_LENGTH_FILE_NAME];
	// The execution filename
	char * execution_file = new char[MAX_LENGTH_FILE_NAME];

	/*
	 * The value of argc specifies what parameters were passed by an user.
	 * The argc always equalls 1, because the first element is itself program.
	 * If the argc is less than 1, it means an user's entered only command name.
	 */
	if (argc == 1 || argc == 4)
	{
		std::cerr << "File isn't found!" << std::endl;
		delete[] execution_file;
		delete[] source_code;
		return 1;
	}
	else if (thereAreFlags == 0)
	{
		// To read and write a source file name to source_code variable 
		for (int i = 0; argv[1][i] != '\0'; i++)
		{
			source_code[i] = argv[1][i];
		}

		getFileName(argv[1], execution_file, 1);

		compilation(source_code, execution_file);
		
	}
	else if (thereAreFlags == 1)
	{
		// To read and write a source file name to source_code variable 
		for (int i = 0; argv[1][i] != '\0'; i++)
		{
			source_code[i] = argv[1][i];
		}
		
		flags = new char[MAX_SYM];
		*(argv + 2) += '\0';
		getFlags(argv[2], flags);
		
		/*
		 * It is the checking that an user've entered only valid flags,
		 * otherwise a program answers that a command is invalid.
		 */
		if (checkFlags(flags) == 0)
		{
			std::cerr << "Invalid command!" << std::endl;
			delete[] flags;
			delete[] source_code;
			delete[] execution_file;
			return 1;
		}

		// To append symbol '\0', that to read char array intill to it.
		*(argv + 1) += '\0';

		if (renameCommand(flags) == 1)
		{
                        if (withoutCommand(flags))
                        {
                                getAnotherFilename(source_code, execution_file);
                                getFileName(source_code, execution_file, 0);
                        }
                        else
                        {
                                getAnotherFilename(source_code, execution_file);
                                getFileName(source_code, execution_file, 1);
                        }       
                }
		else
		{
                        if (withoutCommand(flags))
                        {
			        getFileName(source_code, execution_file, 0);
		        }      
                        else
                        {
			        getFileName(source_code, execution_file, 1);
                        }
                }

		executionScript(flags, source_code, execution_file);

	}
	
	delete[] flags; 
	delete[] source_code;
	delete[] execution_file;

	return 0;
}

/*
 * This method juxtaposes flags with them value and runs them
 * */
void executionScript(const char * flags, char * source_code, char * execution_file)
{
	
	// A program was executed
	bool executed = 0;
	// A execution file was deleted
	bool execution_file_was_deleted = 0;
	// To create the command of terminal for execution an execution file
	char * command_exe = new char[MAX_LENGTH_FILE_NAME];
	// To create the command of terminal for deleting an execution file
	char * delete_command = new char[COMMAND_LENGTH];

	compilation(source_code, execution_file);

	for (int pos = 0; flags[pos] != '\0'; pos++)
	{
		switch (flags[pos])
		{
			case 'n':
				compilation(source_code, execution_file);
				break;
			case 'p':
				std::cout << execution_file << std::endl;
				break;
			case 'e':
			
				strcpy(command_exe, "./");
				strcat(command_exe, execution_file);
				if (executed == 0)
				{
					std::system(command_exe);
				}
				executed = 1;
				break;
			case 'd':
				strcpy(command_exe, "./");
				strcat(command_exe, execution_file);
				if (executed == 0)
				{
					std::system(command_exe);
				}
				strcpy(delete_command, "rm -R ");
				strcat(delete_command, execution_file);
				std::system(delete_command);
                                std::cerr << "Removed file: " << execution_file << std::endl;
				executed = 1;
				execution_file_was_deleted = 1;
				break;
                        case 'w':
				strcpy(command_exe, "./");
				strcat(command_exe, execution_file);
                                break;

		}
		if (executed == 1 && execution_file_was_deleted == 1)
		{
			break;
		}
	}

	delete[] delete_command;
	delete[] command_exe;
}

bool renameCommand(const char * flags)
{
	for (int i = 0; flags[i] != '\0'; i++)
	{
		if (flags[i] == 'n')
		{
			return 1;
		}
	}
	return 0;
}



/*
 * This method checks that all flags are valid for the program.
 * */
bool checkFlags(const char * flags)
{
	bool flag = 0;
	for (int i = 0; flags[i] != '\0'; i++)
	{
		flag = 0;
		for (int j = 0; commands[j] != '\0'; j++)
		{
			if ( flags[i] == commands[j] )
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return 0;
		}
	}
	return 1;
}

/*
 * This method forms flags array
 * */
void getFlags(const char * line, char * flags)
{
	for (int pos = 1; line[pos] != '\0'; pos++)
	{
				
		flags[pos - 1] = line[pos];
		
	}
	*flags += '\0';
}

/*
 * This method creates a execution file name that is the same as source file name.
 * The last bool parameters specifies it needs to include extension exe or not,
 * it allows to get either execution file or simple clean file name.
 * */
void getFileName(const char * line, char * execution_file, bool include_extension)
{
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '.')
		{
			break;
		}
		execution_file[i] = line[i];
	}
	if (include_extension == 1)
	{
		strcat(execution_file, ".exe");
	}
}

/*
 * This method runs compilation a source code.
 * */
void compilation(const char * source_code, const char * execution_file)
{
	char * compilation = new char[255];
	strcpy(compilation, "g++ -Wall -std=c++17 ");
 	strcat(compilation, source_code);
    	strcat(compilation, " -o ");
     	strcat(compilation, execution_file);
	std::system(compilation);
	delete[] compilation;
}

/*
 * The creating a filename.
 * The method checks that a filename was created by itself doesn't exist
 * in the current directory, if the filename exists, then the method create a new.
 * Also, the method creates new file every time, when an user specified the flag 'n'.
 * */
void getAnotherFilename(char * source_code, char * execution_file)
{
	int ID = 1;
	char * filename = nullptr;
	do
	{	
		if (filename != nullptr)
		{	
			delete[] filename;
		}
		filename = new char[MAX_LENGTH_FILE_NAME];
		getFileName(source_code, filename, 0);
		strcat(filename, "_");
	       	strcat(filename, std::to_string(ID++).c_str());
		strcat(filename, ".exe");
	}
	while (std::fstream(filename));
	strcpy(execution_file, filename);
	delete[] filename;
}

bool withoutCommand(const char * flags)
{
    for (int i = 0; flags[i] != '\0'; i++)
    {
        if (flags[i] == 'w')
        {
            return 1;
        }
    }
    return 0;
}
