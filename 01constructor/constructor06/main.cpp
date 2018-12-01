#include <iostream>

using namespace std;


class Member
{
    const char* ms;
public:
    Member(const char* s)
    {
        printf("Member(const char* s): %s\n", s);

        ms = s;
    }
    ~Member()
    {
        printf("~Member(): %s\n", ms);
    }
};

class Test
{
    Member mA;
    Member mB;
public:
    Test() : mB("mB"), mA("mA")
    {
        printf("Test()\n");
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

Member gA("gA");


// stack object ,and global object---->>stack
//heap object, ---->delete
int main()
{
    Test t;

    cout << "Hello World!" << endl;
    return 0;
}

