#include <iostream>

using namespace std;
#include <stdio.h>

class TwoPhaseCons
{
private:
    TwoPhaseCons() // µÚÒ»œ×¶Î¹¹Ôìº¯Êý
    {
    }
    bool construct() // µÚ¶þœ×¶Î¹¹Ôìº¯Êý
    {
        return true;
    }
public:
    static TwoPhaseCons* NewInstance(); // ¶ÔÏóŽŽœšº¯Êý
};

TwoPhaseCons* TwoPhaseCons::NewInstance()
{
    TwoPhaseCons* ret = new TwoPhaseCons();

    // ÈôµÚ¶þœ×¶Î¹¹ÔìÊ§°Ü£¬·µ»Ø NULL
    if( !(ret && ret->construct()) )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}


//harf object avoid
//object are good to place in heap memory, and there is no need copy constructor?
int main()
{
    TwoPhaseCons* obj = TwoPhaseCons::NewInstance();//private constructor

    printf("obj = %p\n", obj);

    delete obj;

    return 0;
}
