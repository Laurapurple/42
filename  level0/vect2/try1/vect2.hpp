/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchar <lbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:31:37 by lbouchar          #+#    #+#             */
/*   Updated: 2026/08/26 12:50:34 by lbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

    int operator [] (int index) const;
    int &operator [] (int index);

    vect2 &operator ++();
    vect2 operator ++(int);
    vect2 &operator --();
    vect2 operator--(int);
    
};

std::ostream &operator << (std::ostream &os, const vect2 &v);