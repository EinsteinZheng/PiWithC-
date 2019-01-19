//
//  number.hpp
//  cpppi
//
//  Created by Einstein Zheng on 1/17/19.
//  Copyright © 2019 Einstein Zheng. All rights reserved.
//

#pragma once

#ifndef number_hpp
#define number_hpp

#include <string>
#include <thread>
#include <math.h>
#include <vector>
#include "fft.hpp"

#endif /* number_hpp */

class num
{
public:
    std::vector<int> _num;
    static const long micro=1000000;
public:
    num();
    num(std::string&);
    num(std::string&&);
    num(const num&);
    virtual ~num();
    num operator+(num);
    num operator-(num);
    num operator*(num);
    num operator/(num);
    num operator+=(num);
    num operator-=(num);
    num operator*=(num);
    num operator/=(num);
    num nomicm(num);
    num sqrt(num);
};
