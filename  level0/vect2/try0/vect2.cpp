/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchar <lbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:16:47 by lbouchar          #+#    #+#             */
/*   Updated: 2026/09/07 15:03:31 by lbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(): _x(0), _y(0) {}

vect2::vect2(int x, int y): _x(x), _y(y) {}

vect2::vect2(const vect2 &copy) { *this = copy; }

vect2 &vect2::operator=(const vect2 &src)
{
    if (this != &src)
    {
        this->_x = src._x;
        this->_y = src._y;
    }
    return (*this);
}

vect2::~vect2() {};

int vect2::operator [] (int index) const
{
    if (index == 0)
        return (this->_x); 
    return (this->_y);
}

int &vect2::operator [] (int index)
{
    if (index == 0)
        return (this->_x); 
    return (this->_y);
}

vect2 vect2::operator + (const vect2 &obj) const
{
    vect2 tmp = *this;
    
    tmp._x += obj._x;
    tmp._y += obj._y;
    return (tmp);
}

vect2 vect2::operator - (const vect2 &obj) const
{
    vect2 tmp = *this;

    tmp._x -= obj._x;
    tmp._y -= obj._y;
    return (tmp);
}

vect2 vect2::operator * (const vect2 &obj) const
{
    vect2 tmp = *this;

    tmp._x *= obj._x;
    tmp._y *= obj._y;
    return (tmp);
}

vect2 &vect2::operator += (const vect2 &obj)
{
    this->_x += obj._x;
    this->_y += obj._y;
    return (*this);
}

vect2 &vect2::operator -= (const vect2 &obj)
{
    this->_x -= obj._x;
    this->_y -= obj._y;
    return (*this);
}

vect2 &vect2::operator *= (const vect2 &obj)
{
    this->_x *= obj._x;
    this->_y *= obj._y;
    return (*this);
}

vect2 &vect2::operator ++()
{
    this->_x += 1;
    this->_y += 1;
    return (*this);
}

vect2 &vect2::operator --()
{
    this->_x -= 1;
    this->_y -= 1;
    return (*this);
}

vect2 vect2::operator ++(int)
{
    vect2 tmp = *this;
    ++(*this);
    return (*this);
}

vect2 vect2::operator --(int)
{
    vect2 tmp = *this;
    --(*this);
    return (*this);
}

bool vect2::operator == (const vect2 &obj) const
{
    if (this->_x == obj._x && this->_y == obj._y)
        return true;
    return false;
}

bool vect2::operator != (const vect2 &obj) const
{
    if (this->_x == obj._x && this->_y == obj._y)
        return false;
    return true;
}

vect2 vect2::operator -() const
{
    vect2 tmp = *this;

    tmp._x = -tmp._x;
    tmp._y = -tmp._y;
    return (tmp);
}

vect2  vect2::operator * (int num) const
{
    vect2 tmp = *this;

    tmp._x = tmp._x * num;
    tmp._y = tmp._y * num;
    return (tmp);
}

vect2 &vect2::operator *= (int num)
{
    this->_x *= num;
    this->_y *= num;
    return (*this);
}

vect2 operator * (int num, const vect2 &obj)
{
    vect2 tmp(obj);
    tmp *= num;
    return tmp;
}

std::ostream &operator << (std::ostream &os, const vect2 &v)
{
     std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
     return (os);
}