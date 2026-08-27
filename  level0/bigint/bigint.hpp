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

        std::string GetResult() const;

        //+ +=
     //   bigint operator + (const bigint &src) const;
    //    bigint &operator += (const bigint &src);

        //++x x++
        bigint &operator ++ ();
        bigint operator ++(int);

        

};

std::ostream &operator << (std::ostream &os, const bigint &src);

#endif