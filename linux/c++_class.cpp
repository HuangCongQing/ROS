/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

#include <iostream>

class A
{
public:
    int i;
    void test()
    {
        std::cout << i << std::endl;
    }
};

int main()
{
    A a;
    
    a.i = 10;
    a.test();
    
    return 0;
}
