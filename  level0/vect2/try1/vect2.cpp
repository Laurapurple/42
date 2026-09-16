/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchar <lbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:36:13 by lbouchar          #+#    #+#             */
/*   Updated: 2026/09/07 15:04:04 by lbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2():_x(0), _y(0) {}
vect2::vect2(int x, int y):_x(x), _y(y) {}
vect2::vect2(const vect2 &copy):_x(copy._x), _y(copy._y){}
vect2 &vect2::operator = (const vect2 &src)
{
    if (this != &src)
    {
        this->_x = src._x;
        this->_y = src._y;
    }
    return *this;
}
vect2::~vect2(){}

int vect2::operator [] (int index) const
{
    if (index = 0)
        return this->_x;
    return this->_y;
    
}
int &vect2::operator [] (int index)
{
  if (index = 0)
        return this->_x;
    return this->_y;
}

vect2 &vect2::operator ++()
{
    this->_x += 1;
    this->_y += 1;
    return *this;
}

vect2 vect2::operator ++(int)
{
    vect2 tmp = *this;

    ++(*this);
    return *this;
}
vect2 &vect2::operator --()
{
    
}

vect2 vect2::operator--(int)
{
    
}

std::ostream &operator << (std::ostream &os, const vect2 &v)
{
    std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
    return (os);
}