#include <iostream>

using namespace std;

class Test
{
    int mi;
public:
    Test(int i);
    Test(const Test& t);
    int getMi() const;
    void print();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
//    mi = t.getMi(); //must call const function
//    mi = t.mi;    // copy constructor function is a special member function ,by this pointer
}

int Test::getMi() const
{
//    mi = 2;
//    ../constructor07/main.cpp:26:8: error: assignment of member 'Test::mi' in read-only object
//         mi = 2;
    return mi;
}

void Test::print()
{
    printf("this = %p\n", this);
}

// all the instance object share the class member function by "this".
int main()
{
    //compile stage can not be change, and in left of "="
    const Test t(1); //read-only object

    Test t1(1);
    Test t2(2);
    Test t3(3);

    printf("t1.getMi() = %d\n", t1.getMi());
    printf("&t1 = %p\n", &t1);
    t1.print();

    printf("t2.getMi() = %d\n", t2.getMi());
    printf("&t2 = %p\n", &t2);
    t2.print();

    printf("t3.getMi() = %d\n", t3.getMi());
    printf("&t3 = %p\n", &t3);
    t3.print();

    return 0;
}
