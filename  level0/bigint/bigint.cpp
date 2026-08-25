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

std::string bigint::GetResult() const
{
    return (this->_result);
}

bigint bigint::operator + (const bigint &other) const
{
    bigint tmp = *this;
    tmp += other;
    return (tmp);
}

std::ostream &operator << (std::ostream &os, const bigint &src)
{
    std::cout << src.GetResult() << std::endl;
    return (os);
}
