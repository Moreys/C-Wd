#ifndef __COWSTRING_H__
#define __COWSTRING_H__
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CowString
{
public:
    CowString();
    CowString(const char * pstr);
    CowString(const CowString & rhs);
    CowString & operator=(const CowString & rhs);
    ~CowString();

    const char * c_str() const {    return _pstr;}
    int size() const { return strlen(_pstr); }
    int refcount() {    return *((int *)(_pstr -4));}//前面存放相应的信息，然后通过对_pstr的偏移然后进行解引用取得前面记录字符串的信息的值是什么
    char & operator[](int idx);
    friend std::ostream & operator<<(std::ostream & os, const CowString & rhs);

private:
    void  initRefcount() { *((int *)(_pstr -4)) = 1;}
    void increaseRefcount() { ++*((int *)(_pstr -4));}
    void decreaseRefcount() { --*((int *)(_pstr -4));}
    void release()
    {
        decreaseRefcount();
        if(0 == refcount())
        {
            delete [] (_pstr -4);
            cout << ">>>>>delete data!" << endl;
        }
    }
private:
    char * _pstr;//指针永远都是指向字符串的
    
};
#endif
