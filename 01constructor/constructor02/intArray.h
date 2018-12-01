#ifndef _INTARRAY_H_
#define _INTARRAY_H_
#include <stdio.h>

class IntArray
{
private:
    int m_length;
    int* m_pointer;
public:
    IntArray(int len);
    IntArray(const IntArray& obj);
    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);
//    void free();
    ~IntArray()
    {
        printf("~IntArray()\n");
        if (!m_pointer)
            delete m_pointer;
    }
};

#endif
