#include <iostream>
#include "intArray.h"

using namespace std;

/**
*   (1) constructor can be overloaded, can have different parameters
*   (2)
*       Test t;     object defined, call constructor
*       extern Test t;      object claim, and tell compiler and linker name
*/
class Test
{
private:
    int m_value;
public:
    Test()
    {
        printf("Test()\n");
        m_value = 0;
    }
    Test(int v)
    {
        printf("Test(int v), v = %d\n", v);
        m_value = v;
    }

    int getValue()
    {
        return m_value;
    }
};

/**
  *
  * how to solve array safely question? please write an array class
**/

int main()
{
    Test t;
    Test t1(1); // object defined, initialize and call construtor
    Test t2 = 2;

//    t = t2;

    int i(100);// object initialize
    printf("i = %d\n", i);
//    Test()
//    Test(int v), v = 1
//    Test(int v), v = 2
//    i = 100

    Test ta[3] = { Test(), Test(1), Test(2)};
    for (int i = 0; i < 3; i++)
    {
        printf("ta[%d].getValue():%d\n", i, ta[i].getValue());
    }
//    Test()
//    Test(int v), v = 1
//    Test(int v), v = 2
//    ta[0].getValue():0
//    ta[1].getValue():1
//    ta[2].getValue():2

    Test g = Test(100);
    printf("t.value:%d\n", g.getValue());
//    Test(int v), v = 100
//    t.value:100

//    IntArray a[5];
    IntArray a(5);

    for (int i = 0; i< a.length(); i++)
    {
        a.set(i , i+1);
    }

    for (int i = 0; i< a.length(); i++)
    {
        int value = 0;
        a.get(i, value);
        printf("i:%d, value:%d\n", i, value);
    }
//i:0, value:1
//i:1, value:2
//i:2, value:3
//i:3, value:4
//i:4, value:5

    IntArray b(a);

    for(int i = 0; i < b.length(); i++)
    {
        int value = 0;
//        printf("b[%d]:%d, %p\n", i , *b.m_pointer[i], b.m_pointer);
        if( b.get(i, value) )
        {
            printf("b[%d] = %d\n", i, value);
        }
    }

//    a.free();// safe place 3
//    b.free();

    return 0;
}
