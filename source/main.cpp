//#include "Ptr_to_T.h"
#include <string.h>
#include <iostream>

//using namespace Ptr;
using std::cout;
using std::cin;
using std::endl;
#include "Ptr_to_T_temp.cpp"

using namespace PtrTemp;

int main()
{
    //Ptr_to_T
    typedef Ptr_to_T<char> Ptr_to_T;
    char v[200]={0};
    strcpy(v,"test_const_cstr");
    Ptr_to_T p(&v[0],v,strlen(v));
    try
    {
        Ptr_to_T temp1=p++;
        //--p;
        //*p='a';
        *temp1='a';
        cout<<temp1<<' '<<p<<endl;
        p[5]='d';
        cout<<temp1<<' '<<p<<endl;
        cout<<v<<endl;
    }
    catch(Range)
    {
        cout<<"Error: bad range!"<<endl;
    }
    ++p;
    p=10+p;
    *p='a';
    try
    {
        cout<<v<<'\t';
        p[1]='c';////
        cout<<p<<endl;
    }
    catch(Range)
    {
        cout<<"Error: bad range!"<<endl;
    }

    cout<<endl;

    //char *
    char u[200]={0};
    strcpy(u,"test_const_cstr");
    char * pCh=&u[0];
    char *temp2=pCh++;
    *temp2='a';
    cout<<temp2<<' '<<pCh<<endl;
    pCh[5]='d';
    cout<<temp2<<' '<<pCh<<endl;
    cout<<u<<endl;

    ++pCh;
    pCh=10+pCh;
    *pCh='a';
    cout<<u<<'\t';
    //pCh[10000]='c';////
    cout<<pCh<<endl;
    return 0;
}
