#include <iostream>
#include <stdio.h>

using namespace std;

//class constructor order

class Test
{
private:
    int mi;
public:
    Test(int i)
    {
        mi = i;
        printf("Test(int i): %d\n", mi);
    }
    Test(const Test& obj)
    {
        mi = obj.mi;
        printf("Test(const Test& obj): %d\n", mi);
    }

    Test(const char* s)
    {
        printf("%s\n", s);
    }
};

/**
 * single object constructor create order
 *
 * 1. father class
 * 2. member class (call order is opposite to claim order)
 * 3. self class
 *
**/

int main()
{
//    int i = 0;
//    Test a1 = i;

//    while( i < 3 )
//    {
//        Test a2 = ++i;
//    }

//    if( i < 4 )
//    {
//        Test a = a1;
//    }
//    else
//    {
//        Test a(100);
//    }

    int i = 0;
    Test* a1 = new Test(i); // Test(int i): 0

    while( ++i < 10 )
        if( i % 2 )
            new Test(i); // Test(int i): 1, 3, 5, 7, 9

goto END;
    if( i < 4 )
        new Test(*a1);
    else
        new Test(100); // Test(int i): 100
END:
    Test t5("t5"); //global object initialize not sure!!!
    return 0;
}
