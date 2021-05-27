#ifndef input_h
#define input_h
#include <cstring>
#include <cstdint>
#include "utility.h"

class Input
{
    public:
        Input() {};
        Input(const char * input[], int length);
        ~Input()
        {
            if (source_code == nullptr)
            {
                delete[] source_code;
            }
            if (file_flags == nullptr)
            {
                delete[] file_flags;
            }
        };
        char * getSourceCode() const
        {
            return this->source_code;
        };
        char * getFileFlags() const
        {
            return this->file_flags;
        };
        int getCompileFlag() const
        {
            return this->compile_flag;
        };
        void setSourceCode(char * source_code)
        {
            int length = static_cast<int>(Utility::length(source_code));
            this->source_code = new char[length + 1];
            this->source_code[length] = '\0';
            strcpy(this->source_code, source_code);
        };
        void setFileFlags(char * file_flags)
        {
            int length = static_cast<int>(Utility::length(file_flags));
            this->file_flags = new char[length + 1];
            this->file_flags[length] = '\0';
            strcpy(this->file_flags, file_flags);
        };
        void setCompileFlag(int compile_flag)
        {
            this->compile_flag = compile_flag;
        };
        Input & operator=(const Input & other) noexcept
        {
           if (this == &other)
           {
               return * this;
           }
           this->setSourceCode(other.getSourceCode());
           this->setCompileFlag(other.getCompileFlag());
           this->setFileFlags(other.getFileFlags());
           return * this;
        };
    private:
        char * source_code = nullptr;
        char * file_flags = nullptr;
        int compile_flag = INT32_MIN;
        static bool checkSourceCode(const char * input_code);

};

#endif // input_h
