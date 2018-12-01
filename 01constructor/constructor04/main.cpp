#include <iostream>
#include <stdio.h>

using namespace std;

class Value{
private:
    int mi;
public:
    Value(int i)
    {
        printf("i:%d\n", i);
        mi  = i;
    }

    int getI()
    {
        return mi;
    }
};

class Test
{
private:
    const int ci;// const member initialize
    Value m1;
    Value m2;
    Value m3;
public:
    Test():m2(1), m1(2), m3(3), ci(100)
    {
        printf("Test()\n");
    }
//    Test():ci(10) // read-only member initialize, prior run constructor, order same as claims
//    {

//    }
//    Test()
//    {
//        ci = 10;
//    }

    int getCI()
    {
        return ci;
    }

    void setCI(int v)
    {
        int *p = const_cast<int *>(&ci);
        *p = v;
    }
};

int main()
{
    Test t1;
//    ../constructor04/main.cpp:10:5: error: uninitialized const member in 'const int' [-fpermissive]
//         Test()
    printf("t.ci:%d\n", t1.getCI());

    t1.setCI(10);

    printf("t.ci:%d\n", t1.getCI());
//i:2
//i:1
//i:3
//Test()
//t.ci:100
//t.ci:10
//Hello World!

    cout << "Hello World!" << endl;
    return 0;
}

