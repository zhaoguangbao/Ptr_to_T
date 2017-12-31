#include <iostream>

namespace PtrTemp//
{
    class Range{};
	template<class T>
    class Ptr_to_T//T*
    {
        T* p;
        T* const array;
        int size;
    public:
        void check(int i)
        {
            if(p+i<array || p+i>array+size)
                throw Range();
        }
        //�봫����ָ��ָ��һ�²�û�п����¿ռ�Ҳ�Ͳ���Ҫ����delete
        Ptr_to_T(T* pin,T* v,int s):p(pin),array(v),size(s){}
        Ptr_to_T(T* pin):p(pin),array(pin),size(1){}

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
            return temp;//���ؾֲ�����
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
            return temp;//���ؾֲ�����
        }

        T& operator*()
        {
            return *p;
        }
        T* operator->();
        T& operator[](int i)
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
        Ptr_to_T& operator=(T c)
        {
            *p=c;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& out,Ptr_to_T<T>& ptr)
        {
            out<<ptr.p;
            return out;
        }
    };
    template<class T>
    Ptr_to_T<T>& operator+(int i,Ptr_to_T<T>& ptr)////
    {
        return ptr+i;
    }

    /*template<class T>
    std::ostream& operator<<(std::ostream& out,Ptr_to_T<T>& ptr)
    {
        out<<ptr.p;
        return out;
    }*/
    //*.cpp

};


