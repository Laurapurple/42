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

        std::string GetResult(void) const;

        bigint operator + (const bigint &other) const;
        bigint &operator += (const bigint &other);

};

std::ostream &operator << (std::ostream &os, const bigint &src);

#endif