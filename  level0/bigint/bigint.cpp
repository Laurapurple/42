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

bigint bigint::operator << (const bigint &obj) const
{
    bigint tmp;
    std::stringstream ss(obj._result);
    unsigned int n;
    ss >> n;
    tmp = (*this) << n;
    return tmp;
}

bigint bigint::operator << (const bigint &obj) const
{
    bigint tmp;
    std::stringstream ss(obj._result);
    unsigned int n;
    ss << n;
    tmp = (*this) >> n;
    return tmp;
}
