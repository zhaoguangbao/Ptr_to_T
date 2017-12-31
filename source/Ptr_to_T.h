#ifndef __PTR_TO_T_H_
#define __PTR_TO_T_H_

#include <iostream>

namespace Ptr//
{
    class Range{};
    class Ptr_to_T//char*
    {
        char* p;
        char* const array;
        int size;
    public:
        void check(int i)
        {
            if(p+i<array || p+i>array+size)
                throw Range();
        }
        //与传来的指针指向一致并没有开辟新空间也就不需要利用delete
        Ptr_to_T(char* pin,char* v,int s):p(pin),array(v),size(s){}
        Ptr_to_T(char* pin):p(pin),array(pin),size(1){}

        Ptr_to_T& operator++()
        {
            check(1);
            p+=1;
            return *this;
        }
        Ptr_to_T operator++(int)
        {
            Ptr_to_T temp=*this;
            check(1);
            p+=1;
            return temp;//返回局部变量
        }

        Ptr_to_T& operator--()
        {
            check(-1);
            p-=1;
            return *this;
        }
        Ptr_to_T operator--(int)////
        {
            Ptr_to_T temp=*this;
            check(-1);
            p-=1;
            return temp;//返回局部变量
        }

        char& operator*()
        {
            return *p;
        }
        char* operator->();
        char& operator[](int i)
        {
            check(i);
            return *(p+i);
        }

        Ptr_to_T& operator+(int i)
        {
            check(i);
            p+=i;
            return *this;
        }

        Ptr_to_T& operator=(Ptr_to_T& ptr)
        {
            /*if(*this==ptr)
                return *this;
            delete this->array;*/
            return ptr;
        }
        Ptr_to_T& operator=(char c)
        {
            *p=c;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& out,Ptr_to_T& ptr);
    };
    Ptr_to_T& operator+(int i,Ptr_to_T& ptr)////
    {
        return ptr+i;
    }

    std::ostream& operator<<(std::ostream& out,Ptr_to_T& ptr)
    {
        out<<ptr.p;
        return out;
    }
    //*.cpp

};

#endif // __PTR_TO_T_H_
