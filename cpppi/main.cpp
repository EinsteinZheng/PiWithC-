//
//  main.cpp
//  cpppi
//
//  Created by Einstein Zheng on 1/16/19.
//  Copyright © 2019 Einstein Zheng. All rights reserved.
//

#include <iostream>
#include "number.hpp"

int main() {
    // insert code here...
    std::string nu2str;
    nu2str.push_back('1');
    nu2str.push_back('.');
    for(int i=0;i<15;i++)
    {
        nu2str.push_back('5');
    }
    num nu("-0.1"),nu2(nu2str);
    nu+=nu2;
    return 0;
}
