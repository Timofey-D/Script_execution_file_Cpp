#ifndef Script_run
#define Script_run

// j
void getAnotherFilename(char * source_code, char * execution_file);

// To compile a source code
void compilation(const char * source_file, const char * execution_file);

// To create an execution filename
void getFileName(const char * line, char * execution_file, bool include_extension);

// To create a char array that contains flags of commands
void getFlags(const char * line, char * flags);

// To check the flags
bool checkFlags(const char * flags);

// The method executes specified commands, it juxteposes entered symbol with command symbol.
void executionScript(const char * flags, char * source_code, char * execution_file);

// To check whether there is a rename command
bool renameCommand(const char * flags);
//
void modeExecution();

// To check whether there is a flag for creating execution file without extension
bool withoutCommand(const char * flags);  

bool existingFile(const char * filename);

#endif // Script_run
