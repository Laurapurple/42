#ifndef BIGINT
#define BIGINT

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

class bigint
{
    private:
        std::string _result;

    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint &copy);
        bigint &operator = (const bigint &src);
        ~bigint();

        bigint operator << (const bigint  &obj) const;
        bigint operator >> (const bigint  &obj) const;
};

#endif