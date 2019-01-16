//
//  main.cpp
//  cpppi
//
//  Created by Einstein Zheng on 1/16/19.
//  Copyright © 2019 Einstein Zheng. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>

long double operation(long double x)
{
    return 2*sqrt(1-x*x);
}

long double interval(long double(*oper)(long double),long double low,long double high,long double step)
{
    if(low>high)
    {
        std::swap(low,high);
    }
    long double width=(high-low)/step;
    long double result=0.0,now=low;
    for(int i=0;i<step;i++)
    {
        std::cout<<"now : "<<std::setiosflags(std::ios::fixed)<<std::setprecision(100)<<now<<std::endl<<std::endl;
        result+=oper(now)*width;
        now+=width;
    }
    return result;
}

int main() {
    // insert code here...
    std::cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(100)<<interval(operation,-1.0,1.0,100000000000)<<std::endl;
    return 0;
}
