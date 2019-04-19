#include <iostream>

using namespace std;

/**  内存布局:
*	【1】 class 是特殊的struct, 成员函数与成员变量分开存放， 
          每个对象有独立的成员变量，所有对象共享类中的成员函数，
		  遵循相同的内存对齐规则。
	【2】运行时的对象退化为结构体的形式，成员变量可能存在内存空隙， 可以通过内存地址直接访问成员变量，访问权限关键字在运行时失效
	【3】类中的成员函数位于代码段中，调用成员函数时，对象地址作为参数隐式传递，成员函数时通过对象地址来访问成员变量的，也就是(.)操作符。
*/
#include <iostream>
#include <string>

using namespace std;

class Demo
{
protected:
    int mi;
    int mj;
public:
    virtual void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << endl;
    }
//    virtual void push()
//    {

//    }
};

class Derived : public Demo
{
    int mk;
public:
    Derived(int i, int j, int k)
    {
        mi = i;
        mj = j;
        mk = k;
    }

    virtual void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << ", "
             << "mk = " << mk << endl;
    }
//    virtual void push()
//    {

//    }

};

struct Test
{
    void* p;
    int mi;
    int mj;
    int mk;
};

int main()
{
    cout << "sizeof(Demo) = " << sizeof(Demo) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    Derived d(1, 2, 3);
    Test* p = reinterpret_cast<Test*>(&d);

    cout << "Before changing ..." << endl;

    d.print();

    p->mi = 10;
    p->mj = 20;
    p->mk = 30;

    (reinterpret_cast<Derived *>(p->p))->print();

    cout << "After changing ..." << endl;

    d.print();

    return 0;
}
