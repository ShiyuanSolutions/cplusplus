#include <iostream>
#include <memory>

//https://www.jianshu.com/p/e4919f1c3a28
using namespace std;

class Test{
public:
    Test(int a = 0):m_a(a){ }
    ~Test()
    {
        cout << " Calling destruct " << endl;
    }

public:
    int m_a;
};

void Fun( )
{
     cout << "Func" << endl;
     int a = 0, b= 5, c;
     if( a == 0 )
     {
      throw "Invalid divisor";
     }
     cout << "Func2" << endl;

     c = b/a;

     cout << "Func3" << endl;

     return;
}

void Fun(auto_ptr<Test> p1 )
{
 cout<<p1->m_a<<endl;
}


class B;
class A
{
public:
 A(  ) : m_a(5)  { };
 ~A( )
 {
  cout<<" A is destroyed"<<endl;
 }
 void PrintSpB( );
 weak_ptr<B> m_sptrB;
 int m_a;
};

class B
{
public:
 B(  ) : m_b(10) { };
 ~B( )
 {
  cout<<" B is destroyed"<<endl;
 }
 weak_ptr<A> m_sptrA;
 int m_b;
};

void A::PrintSpB( )
{
 if( !m_sptrB.expired() )
 {
  cout<< m_sptrB.lock( )->m_b<<endl;
 }
}

int main()
{
//    cout << "Hello World!" << endl;
//    std::auto_ptr<Test>p(new Test(5));
//    cout << p->m_a << endl;

//    try
//    {
//     std::auto_ptr<Test> p( new Test(5) );
//     Fun( );
//     cout<<p->m_a<<endl;
//    }
//    catch(...)
//    {
//     cout<<"Something has gone wrong"<<endl;
//    }

//    std::auto_ptr<Test> p( new Test(5) );
//    Fun(p);
//    cout<<p->m_a<<endl;

//    std::auto_ptr<Test> p(new Test[5]);

//    std::shared_ptr<int> p (new int(100));
//    p.reset();

//    cout << p.use_count() << endl;
//lamda
//    std::shared_ptr<Test> sptr1( new Test[5],
//            [ ](Test *p){ delete [] p; });

//    std::shared_ptr<Test> sptr2 = sptr1;
//    cout << sptr2.unique() << endl;

//    int* p = new int;
//    shared_ptr<int> sptr1( p);
//    shared_ptr<int> sptr2( p );

//    shared_ptr<B> sptrB( new B );
//    shared_ptr<A> sptrA( new A );
//    sptrB->m_sptrA = sptrA;
//    sptrA->m_sptrB = sptrB;
//    sptrA->PrintSpB( );

//    shared_ptr<Test> sptr( new Test );
//    weak_ptr<Test> wptr( sptr );
//    weak_ptr<Test> wptr1 = wptr;

    unique_ptr<int > uptr (new int);

    unique_ptr<int []> uptr(new int[5]);

    cout << "Hello world" << endl;
    return 0;
}

