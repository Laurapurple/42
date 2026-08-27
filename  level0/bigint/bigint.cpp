#include "bigint.hpp"

bigint::bigint(): _result("0") {}
bigint::bigint(unsigned int n) : _result(std::to_string(n)) {}
bigint::bigint(const bigint &copy) : _result(copy._result) {}

bigint &bigint::operator = (const bigint &src)
{
    if (this != &src)
        this->_result = src._result;
    return (*this);
}

bigint::~bigint(){}

std::string bigint::GetResult()const
{
    return(this->_result);
}

// bigint bigint::operator + (const bigint &src) const
// {
//     bigint tmp(*this);
//     tmp += src;
//     return (tmp);
// }



std::ostream &operator << (std::ostream &os, const bigint &src)
{
    os << src.GetResult();
    return (os);
}