//
//  number.cpp
//  cpppi
//
//  Created by Einstein Zheng on 1/17/19.
//  Copyright © 2019 Einstein Zheng. All rights reserved.
//

#include "number.hpp"

num::num()
{
    
}

num::~num()
{
    
}

num::num(const num& nu)
{
    this->_num=nu._num;
}

num::num(std::string&& str)
{
    long point=0;
    bool bz=false,uz=true;
    point=str.find('.');
    if(point==-1)
    {
        point=str.size();
    }
    std::string befp;
    std::vector<std::string> aftp;
    for(int i=0;i<point;i++)
    {
        befp.push_back(str[i]);
    }
    for(long i=point+1;i<str.size()&&i<=micro+point+2;i++)
    {
        std::string buf;
        buf.push_back(str[i]);
        aftp.push_back(buf);
    }
    _num.push_back(atoi((char*)befp.c_str()));
    if(befp[0]=='-')
    {
        bz=true;
    }
    for(int i=0;i<aftp.size();i++)
    {
        if(bz==false)
            _num.push_back(atoi((char*)aftp[i].c_str()));
        else
            _num.push_back(0-atoi((char*)aftp[i].c_str()));
    }
    if(_num.size()>micro+1)
    {
        if(*(_num.end()-1)>=5)
        {
            ++(*(_num.end()-2));
        }
        _num.erase(_num.end()-1);
    }
    bool retry=false;
    do
    {
        retry=false;
        if(_num[0]<0)
        {
            uz=false;
        }
        for(long i=_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(_num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=_num[i]%10;
                    up=(_num[i]-now)/10;
                    _num[i-1]+=up;
                    _num[i]=now;
                    retry=true;
                }
                else if(_num[i]<0&&i!=0)
                {
                    _num[i-1]--;
                    _num[i]=10+_num[i];
                    retry=true;
                }
            }
            else
            {
                if(_num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(_num[i])%10);
                    up=-(-(_num[i])+now)/10;
                    _num[i-1]+=up;
                    _num[i]=now;
                    retry=true;
                }
                else if(_num[i]>0&&i!=0)
                {
                    _num[i-1]++;
                    _num[i]=-10+_num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return;
}

num::num(std::string& str)
{
    long point=0;
    bool bz=false,uz=true;
    point=str.find('.');
    if(point==-1)
    {
        point=str.size();
    }
    std::string befp;
    std::vector<std::string> aftp;
    for(int i=0;i<point;i++)
    {
        befp.push_back(str[i]);
    }
    for(long i=point+1;i<str.size()&&i<=micro+point+2;i++)
    {
        std::string buf;
        buf.push_back(str[i]);
        aftp.push_back(buf);
    }
    _num.push_back(atoi((char*)befp.c_str()));
    if(befp[0]=='-')
    {
        bz=true;
    }
    for(int i=0;i<aftp.size();i++)
    {
        if(bz==false)
            _num.push_back(atoi((char*)aftp[i].c_str()));
        else
            _num.push_back(0-atoi((char*)aftp[i].c_str()));
    }
    if(_num.size()>micro+1)
    {
        if(*(_num.end()-1)>=5)
        {
            ++(*(_num.end()-2));
        }
        _num.erase(_num.end()-1);
    }
    bool retry=false;
    do
    {
        retry=false;
        if(_num[0]<0)
        {
            uz=false;
        }
        for(long i=_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(_num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=_num[i]%10;
                    up=(_num[i]-now)/10;
                    _num[i-1]+=up;
                    _num[i]=now;
                    retry=true;
                }
                else if(_num[i]<0&&i!=0)
                {
                    _num[i-1]--;
                    _num[i]=10+_num[i];
                    retry=true;
                }
            }
            else
            {
                if(_num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(_num[i])%10);
                    up=-(-(_num[i])+now)/10;
                    _num[i-1]+=up;
                    _num[i]=now;
                    retry=true;
                }
                else if(_num[i]>0&&i!=0)
                {
                    _num[i-1]++;
                    _num[i]=-10+_num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return;
}

num num::operator+(num _2)
{
    num result;
    bool uz=true;
    std::fill(result._num.begin(),result._num.end(),0);
    if(_2._num.size()>this->_num.size())
    {
        long a=_2._num.size()-this->_num.size();
        for(int i=0;i<a;i++)
        {
            this->_num.push_back(0);
        }
    }
    else if(_2._num.size()<this->_num.size())
    {
        long a=this->_num.size()-_2._num.size();
        for(int i=0;i<a;i++)
        {
            _2._num.push_back(0);
        }
    }
    result._num.reserve(this->_num.size());
    result._num.resize(this->_num.size());
    for(int i=0;i<result._num.size();i++)
    {
        result._num[i]=0;
    }
    //thread++
    for(long i=this->_num.size()-1;i>=0;i--)
    {
        result._num[i]=this->_num[i]+_2._num[i];
    }
    bool retry=false;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return result;
}

num num::operator-(num _2)
{
    num result;
    bool uz=true;
    std::fill(result._num.begin(),result._num.end(),0);
    if(_2._num.size()>this->_num.size())
    {
        long a=_2._num.size()-this->_num.size();
        for(int i=0;i<a;i++)
        {
            this->_num.push_back(0);
        }
    }
    else if(_2._num.size()<this->_num.size())
    {
        long a=this->_num.size()-_2._num.size();
        for(int i=0;i<a;i++)
        {
            _2._num.push_back(0);
        }
    }
    result._num.reserve(this->_num.size());
    result._num.resize(this->_num.size());
    //thread++
    for(long i=this->_num.size()-1;i>=0;i--)
    {
        result._num[i]=this->_num[i]-_2._num[i];
    }
    bool retry=false;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return result;
}

num num::operator*(num _2)
{
    num result;
    bool uz=true;
    result._num.reserve(this->_num.size()+_2._num.size()-1);
    result._num.resize(this->_num.size()+_2._num.size()-1);
    std::fill(result._num.begin(),result._num.end(),0);
    //thread++
    for(long i=0;i<this->_num.size();i++)
    {
        for(long j=0;j<_2._num.size();j++)
        {
            result._num[result._num.size()-i-j-1]+=this->_num[this->_num.size()-i-1]*_2._num[_2._num.size()-j-1];
        }
    }
    bool retry=false;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    if(result._num.size()>micro+1)
    {
        result._num.erase(result._num.begin()+micro+2, result._num.end());
        if(*(result._num.end()-1)>=5)
        {
            ++(*(result._num.end()-2));
        }
        result._num.erase(result._num.end()-1);
    }
    retry=false;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return result;
}

num num::nomicm(num _2)
{
    num result;
    bool uz=true;
    result._num.reserve(this->_num.size()+_2._num.size()-1);
    result._num.resize(this->_num.size()+_2._num.size()-1);
    std::fill(result._num.begin(),result._num.end(),0);
    //thread++
    for(long i=0;i<this->_num.size();i++)
    {
        for(long j=0;j<_2._num.size();j++)
        {
            result._num[result._num.size()-i-j-1]+=this->_num[this->_num.size()-i-1]*_2._num[_2._num.size()-j-1];
        }
    }
    bool retry=false;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return result;
}

num num::operator/(num _2)
{
    num result,before("0");
    double begin=(double)(this->_num[0])/(double)(_2._num[0]);
    result=num(std::to_string(begin));
    bool change=true;
    while(change)
    {
        change=false;
        before=result;
        result=result*(num("2")-_2.nomicm(result));
        for(int i=0;i<micro+1&&i<result._num.size()&&i<before._num.size();i++)
        {
            if(result._num[i]!=before._num[i])
            {
                change=true;
                i=micro+2;
            }
        }
    }
    if(result._num.size()>micro+1)
    {
        result._num.erase(result._num.begin()+micro+2, result._num.end());
        if(*(result._num.end()-1)>=5)
        {
            ++(*(result._num.end()-2));
        }
        result._num.erase(result._num.end()-1);
    }
    bool retry=false,uz=true;
    do
    {
        retry=false;
        if(result._num[0]<0)
        {
            uz=false;
        }
        for(long i=this->_num.size()-1;i>=0;i--)
        {
            if(uz==true)
            {
                if(result._num[i]>=10&&i!=0)
                {
                    int now=0,up=0;
                    now=result._num[i]%10;
                    up=(result._num[i]-now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]<0&&i!=0)
                {
                    result._num[i-1]--;
                    result._num[i]=10+result._num[i];
                    retry=true;
                }
            }
            else
            {
                if(result._num[i]<=-10&&i!=0)
                {
                    int now=0,up=0;
                    now=-(-(result._num[i])%10);
                    up=-(-(result._num[i])+now)/10;
                    result._num[i-1]+=up;
                    result._num[i]=now;
                    retry=true;
                }
                else if(result._num[i]>0&&i!=0)
                {
                    result._num[i-1]++;
                    result._num[i]=-10+result._num[i];
                    retry=true;
                }
            }
        }
    }while(retry);
    return (*this)*result;
}

num num::operator+=(num _2)
{
    *this=*this+_2;
    return *this;
}

num num::operator-=(num _2)
{
    *this=*this-_2;
    return *this;
}

num num::operator*=(num _2)
{
    *this=*this*_2;
    return *this;
}

num num::operator/=(num _2)
{
    *this=*this/_2;
    return *this;
}
