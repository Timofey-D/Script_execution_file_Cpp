#include <cstring>
#include "utility.h"

bool Utility::thereIsChar(const char * source, char symbol)
{
    for (size_t i = 0; source[i] != '\0'; i++)
    {
        if (source[i] == symbol)
        {
            return 1;
        }
    }
    return 0;
}


size_t Utility::length(const char * source)
{
    size_t length = 0;
    for (; source[length] != '\0'; length++);
    return length;
}


size_t Utility::filenameLength(const char * file, char delimiter)
{
    size_t length = 0;
    for (; file[length] != delimiter; length++);
    return length;
}
