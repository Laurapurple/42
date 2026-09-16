/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchar <lbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:16:21 by lbouchar          #+#    #+#             */
/*   Updated: 2026/08/20 12:50:02 by lbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
    private:
        int _x;
        int _y;
    
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2 &copy);
        vect2 &operator = (const vect2 &src);
        ~vect2();

        // [] const[]
        int operator [] (int index) const;
        int &operator [] (int index);

        // + - *
        vect2 operator + (const vect2 &obj) const;
        vect2 operator - (const vect2 &obj) const;
        vect2 operator * (const vect2 &obj) const;

        // += -= *=
        vect2 &operator += (const vect2 &obj);
        vect2 &operator -= (const vect2 &obj);
        vect2 &operator *= (const vect2 &obj);

        // ++x --x x++ x--
        vect2 &operator ++();
        vect2 &operator --();
        vect2 operator ++(int);
        vect2 operator --(int);

        // != ==
        bool operator == (const vect2 &obj) const;
        bool operator != (const vect2 &obj) const;

        vect2 operator -() const;
        vect2 operator *(int num) const;
        vect2 &operator *= (int num);
};

vect2 operator * (int num, const vect2 &obj);
std::ostream &operator << (std::ostream &os, const vect2 &v);

#endif