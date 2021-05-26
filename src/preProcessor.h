#ifndef PreProcessor_h
#define PreProcessor_h
#include <fstream>

class PreProcessor
{
    public:
        PreProcessor(const char * source_code, const char * file_flags);
        ~PreProcessor()
        {
            delete[] execution_file;
        };
        
        char * getExecutionFile()
        {
            return this->execution_file;
        }
    private:
       char * execution_file = nullptr;

       static constexpr const char * all_pre_compile_flags = "nwp\0";

       static void getFilename(const char * source_code, char * target_file);
       static bool thereIsChar(const char * source, const char symbol)
       {
           for (int i = 0; source[i] != '\0'; i++)
           {
               if (source[i] == symbol)
               {
                   return 1;
               }
           }
           return 0;
       };
       bool checkFileExe(const char * filename)
       {
           std::fstream file(filename);
           return file.good();
       };
       void createExeFile(const bool & new_file, const bool & extension);
       void executionFlags(const char * flags)
       {
            this->createExeFile(thereIsChar(flags, 'n'), thereIsChar(flags, 'w'));

            if (thereIsChar(flags, 'p'))
            {
                std::cout << this->execution_file << std::endl;
            }
       };
};

#endif // PreProcessor_h
