#ifndef postProcessor_h
#define postProcessor_h

class PostProcessor
{
    public:
        PostProcessor(const char * execution, const char * flags);

    private:
        static constexpr const char * all_post_compile_flags = "de\0";

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
        }
        void executeCommand(const char * flags, const char * execution);
};
#endif // postProcessor_h
