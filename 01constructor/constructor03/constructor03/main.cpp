#include <iostream>

using namespace std;

#include <stdio.h>

class Test
{
private:
    int i;
    int j;
    int* p;
public:
    int getI()
    {
        return i;
    }

    int getJ()
    {
        return j;
    }

    int* getP()
    {
        return p;
    }

 /**
*
*   deep copy
*   [1] use the system resource, such as port use, malloc memory, file operation handler in extern memory
*/
    Test(const Test& t)
    {
        i = t.i;
        j = t.j;
        p = new int;

        *p = *t.p;
    }

//    *** Error in `/home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03': double free or corruption (fasttop): 0x0000000000eb9c20 ***
//    ======= Backtrace: =========
//    /lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f4f8c1427e5]
//    /lib/x86_64-linux-gnu/libc.so.6(+0x8037a)[0x7f4f8c14b37a]
//    /lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7f4f8c14f53c]
//    /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03[0x400a5c]
//    /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03[0x40093f]
//    /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f4f8c0eb830]
//    /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03[0x400719]
//    ======= Memory map: ========
//    00400000-00401000 r-xp 00000000 08:02 12584154                           /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03
//    00600000-00601000 r--p 00000000 08:02 12584154                           /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03
//    00601000-00602000 rw-p 00001000 08:02 12584154                           /home/xuzhu/work/git/cplusplus/01constructor/constructor03/build-constructor03-Desktop-Debug/constructor03
//    00ea8000-00eda000 rw-p 00000000 00:00 0                                  [heap]
//    7f4f84000000-7f4f84021000 rw-p 00000000 00:00 0
//    7f4f84021000-7f4f88000000 ---p 00000000 00:00 0
//    7f4f8bbac000-7f4f8bbc2000 r-xp 00000000 08:02 52171191                   /lib/x86_64-linux-gnu/libgcc_s.so.1
//    7f4f8bbc2000-7f4f8bdc1000 ---p 00016000 08:02 52171191                   /lib/x86_64-linux-gnu/libgcc_s.so.1
//    7f4f8bdc1000-7f4f8bdc2000 rw-p 00015000 08:02 52171191                   /lib/x86_64-linux-gnu/libgcc_s.so.1
//    7f4f8bdc2000-7f4f8beca000 r-xp 00000000 08:02 52168156                   /lib/x86_64-linux-gnu/libm-2.23.so
//    7f4f8beca000-7f4f8c0c9000 ---p 00108000 08:02 52168156                   /lib/x86_64-linux-gnu/libm-2.23.so
//    7f4f8c0c9000-7f4f8c0ca000 r--p 00107000 08:02 52168156                   /lib/x86_64-linux-gnu/libm-2.23.so
//    7f4f8c0ca000-7f4f8c0cb000 rw-p 00108000 08:02 52168156                   /lib/x86_64-linux-gnu/libm-2.23.so
//    7f4f8c0cb000-7f4f8c28b000 r-xp 00000000 08:02 52168166                   /lib/x86_64-linux-gnu/libc-2.23.so
//    7f4f8c28b000-7f4f8c48b000 ---p 001c0000 08:02 52168166                   /lib/x86_64-linux-gnu/libc-2.23.so
//    7f4f8c48b000-7f4f8c48f000 r--p 001c0000 08:02 52168166                   /lib/x86_64-linux-gnu/libc-2.23.so
//    7f4f8c48f000-7f4f8c491000 rw-p 001c4000 08:02 52168166                   /lib/x86_64-linux-gnu/libc-2.23.so
//    7f4f8c491000-7f4f8c495000 rw-p 00000000 00:00 0
//    7f4f8c495000-7f4f8c607000 r-xp 00000000 08:02 51120262                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
//    7f4f8c607000-7f4f8c807000 ---p 00172000 08:02 51120262                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
//    7f4f8c807000-7f4f8c811000 r--p 00172000 08:02 51120262                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
//    7f4f8c811000-7f4f8c813000 rw-p 0017c000 08:02 51120262                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
//    7f4f8c813000-7f4f8c817000 rw-p 00000000 00:00 0
//    7f4f8c817000-7f4f8c83d000 r-xp 00000000 08:02 52168159                   /lib/x86_64-linux-gnu/ld-2.23.so
//    7f4f8ca1c000-7f4f8ca22000 rw-p 00000000 00:00 0
//    7f4f8ca3b000-7f4f8ca3c000 rw-p 00000000 00:00 0
//    7f4f8ca3c000-7f4f8ca3d000 r--p 00025000 08:02 52168159                   /lib/x86_64-linux-gnu/ld-2.23.so
//    7f4f8ca3d000-7f4f8ca3e000 rw-p 00026000 08:02 52168159                   /lib/x86_64-linux-gnu/ld-2.23.so
//    7f4f8ca3e000-7f4f8ca3f000 rw-p 00000000 00:00 0
//    7ffe94885000-7ffe948a6000 rw-p 00000000 00:00 0                          [stack]
//    7ffe948ed000-7ffe948f0000 r--p 00000000 00:00 0                          [vvar]
//    7ffe948f0000-7ffe948f2000 r-xp 00000000 00:00 0                          [vdso]
//    ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]

    Test(int v)
    {
        i = 1;
        j = 2;
        p = new int;

        *p = v;
    }

    void free()
    {
        delete p;
    }
};

//compiler provide default no paramter constructor
//Test()
//{
//}
//
class T
{};

int main()
{
    Test t1(2);
    Test t2 = t1;
    printf("t1.i = %d, t1.j:%d\n", t1.getI(), t1.getJ());
    printf("t2.i = %d, t2.j:%d\n", t2.getI(), t2.getJ());

//    main.cpp:41:10: error: no matching function for call to ‘Test::Test()’
    printf("t1.i = %d, t1.j = %d, *t1.p = %d, t1:%p\n", t1.getI(), t1.getJ(), *t1.getP(), t1.getP());
    printf("t2.i = %d, t2.j = %d, *t2.p = %d, t2:%p\n", t2.getI(), t2.getJ(), *t2.getP(),t2.getP());

//    t1.i = 1, t1.j:2
//    t2.i = 1, t2.j:2
//    t1.i = 1, t1.j = 2, *t1.p = 2, t1:0x22bac20
//    t2.i = 1, t2.j = 2, *t2.p = 2, t2:0x22bac40

    t1.free();
    t2.free();
//    cout << "Hello World!" << endl;
    return 0;
}

