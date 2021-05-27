#ifndef utility_h
#define utility_h

class Utility
{
    public:
        static bool thereIsChar(const char * source, char symbol);
        static size_t length(const char * source);
        static size_t filenameLength(const char * file, char delimiter);
};
#endif // utility_h
