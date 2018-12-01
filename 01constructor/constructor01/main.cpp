#include <iostream>

using namespace std;

/**
  * Q1:
  * how to init an object in stack or heap
*/
class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }
//    void initialize()
//    {
//        i = 1;
//        j = 2;
//    }
    // no return value, and same name as class name, AUTO called when object defined
    Test()
    {
        i = 1;
        j = 2;
    }
};

Test gt;

int main()
{
//    gt.initialize();

    Test t1;
//    t1.initialize();

    printf("i:%d\n", t1.getI());
    printf("j:%d\n", t1.getJ());
//i:1274537440
//j:32764

    printf("gi:%d\n", gt.getI());
    printf("gj:%d\n", gt.getJ());
//gi:0
//gj:0

    Test *pt = new Test;
//    pt->initialize(); //call it right now sequence
    printf("pi:%d\n", pt->getI());
    printf("pj:%d\n", pt->getJ());
//may be a coincidence
//pi:0
//pj:0

    delete pt;

    cout << "Hello World!" << endl;
    return 0;
}

