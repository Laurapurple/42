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

<<<<<<< HEAD
        std::string GetResult() const;

        //+ +=
     //   bigint operator + (const bigint &src) const;
    //    bigint &operator += (const bigint &src);

        //++x x++
        bigint &operator ++ ();
        bigint operator ++(int);

        
=======
        std::string GetResult(void) const;

        bigint operator + (const bigint &other) const;
        bigint &operator += (const bigint &other);
>>>>>>> 9367fa7b4ce3520b0432109b1a9afd1d8b930b44

};

std::ostream &operator << (std::ostream &os, const bigint &src);

#endif