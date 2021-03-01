#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <fstream>
#include <iomanip>
#include <cstdio>

#define MAX_SYM 16
#define MAX_LENGTH_FILE_NAME 255 


void getAnotherFilename(char * execution_file);
void compilation(std::string source_file, const char * execution_file);
void getFileName(const char * line, char * execution_file);
void getFlags(const char * line, char * flags);


int main(int argc, const char * argv[])
{
	/*
	 * The script helps to save time and allows to compile and run C++ program via one command.
	 * Command looks like "run filename -flag"
	 * run filename => to compile a program
	 * run filename -e => to run a pragram right now after compilation
	 * run filename -p => to print a name of execution file
	 * run filename -n => to create new execution file without removing previous execution file 
	*/

 	bool thereAreFlags = argc > 2; 
	char * flags = nullptr;
	bool execution_flag = 0;
	bool print_name_flag = 0;
	bool another_filename_flag = 0;

	if (thereAreFlags)
	{
		flags = new char[MAX_SYM];
		*(argv + 2) += '\0';
		getFlags(argv[2], flags);
	}
	
	if (flags != nullptr)
	{
	
		for (int pos = 0; flags[pos] != '\0'; pos++)
		{
			switch (flags[pos])
			{
				case 'e':
					execution_flag = 1;
					break;
				case 'p':
					print_name_flag = 1;
					break;
				case 'n':	
					another_filename_flag = 1;
					break;	
			}
		}
	}

	if (argc <= 1)
	{
		std::cerr << "File isn't found!" << std::endl;
	}
	else
	{
		std::string source_file = argv[1];
		
		char * execution_file = new char[MAX_LENGTH_FILE_NAME];
		
		if (another_filename_flag)
		{
			getAnotherFilename(execution_file);
		}
		else
		{
			argv[1] += '\0';
			getFileName(argv[1], execution_file);
		}

		compilation(source_file, execution_file);
		
		if (print_name_flag)
		{
			std::cout << execution_file << std::endl;
		}
		if (execution_flag)
		{
			char * command_exe = new char[MAX_LENGTH_FILE_NAME];
			strcpy(command_exe, "./");
			strcat(command_exe, execution_file);
			std::system(command_exe);
			delete[] command_exe;
		}

		delete[] execution_file;
	}

	delete flags; 

	return 0;
}

void getFlags(const char * line, char * flags)
{
	for (int pos = 1; line[pos] != '\0'; pos++)
	{
		
		flags[pos - 1] = line[pos];
		
	}
	*flags += '\0';
}

void getFileName(const char * line, char * execution_file)
{
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '.')
		{
			break;
		}
		execution_file[i] = line[i];
	}

	strcat(execution_file, ".exe");
}


void compilation(std::string source_file, const char * execution_file)
{
	std::string compilation = "g++ -Wall -std=c++17 " + source_file + " -o " + execution_file;
	std::system(compilation.c_str());
}


void getAnotherFilename(char * execution_file)
{
	int ID = 1;
	do
	{	
		std::string name = "run_" + std::to_string(ID);
		strcpy(execution_file, name.c_str());
		strcat(execution_file, ".exe");
		ID++;
	}
	while (std::fstream(execution_file));
}	
