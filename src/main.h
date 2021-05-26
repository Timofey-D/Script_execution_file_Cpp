#ifndef main_h
#define main_h
#include <fstream>

inline bool thereIsFile(char * filename)
{
    std::fstream file(filename);
    return file.good();
}

#endif // main_h

