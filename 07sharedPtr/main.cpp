#include <iostream>
#include <memory>

using namespace std;
class Person
{
public:
    Person(int v) {
        value = v;
        std::cout << "Cons" <<value<< std::endl;
    }
    ~Person() {
        std::cout << "Des" <<value<< std::endl;
    }

    int value;

};

struct AStruct;
struct BStruct;

struct AStruct {
    std::shared_ptr<BStruct> bPtr;
    ~AStruct() { cout << "AStruct is deleted!"<<endl; }
};

struct BStruct {
    std::shared_ptr<AStruct> APtr;
    ~BStruct() { cout << "BStruct is deleted!" << endl; }
};


int main()
{

/***
*
*结果没问题啊，先构造对象1和对象2，
*然后reset操作包含两步，第一步是构造新对象，也就是构造对象3，第二步是销毁旧对象，也就是对象1；
*之后连续对智能指针p1进行两次计数减操作，导致对象3的引用计数为0，故对象3销毁；
*最后return 0时，智能指针p2由于在栈上，销毁栈对象p2时，其所指向的对象2也就销毁了。
*/
    std::shared_ptr<Person> p1(new Person(1));
    std::shared_ptr<Person> p2 = std::make_shared<Person>(2);
    cout << "Hello World!" << endl;

    p1.reset(new Person(3));// 首先生成新对象，然后引用计数减1，引用计数为0，故析构Person(1)
                            // 最后将新对象的指针交给智能指针

    std::shared_ptr<Person> p3 = p1;//现在p1和p3同时指向Person(3)，Person(3)的引用计数为2

/*
 * reset()包含两个操作。当智能指针中有值的时候，调用reset()会使引用计数减1.
 * 当调用reset（new xxx())重新赋值时，
 * 智能指针首先是生成新对象，然后将就对象的引用计数减1（当然，如果发现引用计数为0时，则析构旧对象），
 * 然后将新对象的指针交给智能指针保管。
*/
    p1.reset();//Person(3)的引用计数为1
    p3.reset();//Person(3)的引用计数为0，析构Person(3)

//注意，不能将一个原始指针直接赋值给一个智能指针，如下所示，原因是一个是类，一个是指针。
//    std::shared_ptr<int> p4 = new int(1);

    std::shared_ptr<int> p4(new int(5));
    int *pInt = p4.get();
    cout << "pInt:"<< pInt << endl;

/**
使用shared_ptr需要注意的问题
但凡一些高级的用法，使用时都有不少陷阱。
不要用一个原始指针初始化多个shared_ptr，原因在于，会造成二次销毁，如下所示：

int *p5 = new int;
std::shared_ptr<int> p6(p5);
std::shared_ptr<int> p7(p5);// logic error

不要在函数实参中创建shared_ptr。因为C++的函数参数的计算顺序在不同的编译器下是不同的。正确的做法是先创建好，然后再传入。
function(shared_ptr<int>(new int), g());
禁止通过shared_from_this()返回this指针，这样做可能也会造成二次析构。
避免循环引用。智能指针最大的一个陷阱是循环引用，循环引用会导致内存泄漏。解决方法是AStruct或BStruct改为weak_ptr。
*/


    return 0;
}

