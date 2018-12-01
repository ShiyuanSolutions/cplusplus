#include <iostream>

using namespace std;

//member varibale private
#include <stdio.h>

class Test
{
//private:
//    static int cCount; // global memery, share by all the class,
private:
    static int cCount; // global memery, share by all the class,
public:
    Test()
    {
        cCount++;
    }
    ~Test()
    {
        --cCount;
    }
    static int GetCount()
    {
        return cCount;
    }
};

int Test::cCount = 0; //defined

//Test gTest;

//when no object, the result is zero
int main()
{
//    Test t1;
//    Test t2;

//    printf("count = %d\n", gTest.getCount());
//    printf("count = %d\n", t1.getCount());
//    printf("count = %d\n", t2.getCount());

//    Test* pt = new Test();

//    printf("count = %d\n", pt->getCount());

//    delete pt;

//    printf("count = %d\n", gTest.getCount());

//    printf("cout:%d\n", Test::cCount);

//    Test::cCount = 1000;// not safe--->staic member function
//    printf("cout:%d\n", Test::cCount);

    //can be called anytime, so no need to instance Test. initialize without
    printf("count = %d\n", Test::GetCount());

    Test t1;
    Test t2;

    printf("count = %d\n", t1.GetCount());
    printf("count = %d\n", t2.GetCount());

    Test* pt = new Test();

    printf("count = %d\n", pt->GetCount());

    delete pt;

    printf("count = %d\n", Test::GetCount());
    return 0;
}
