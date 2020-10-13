#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>
 
struct A {
    A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
    A(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
    A(const int& n) { std::cout << "const lvalue overload, n=" << n << "\n"; }
};
 
class B {
public:
    template<class T1, class T2, class T3>
    B(T1&& t1, T2&& t2, T3&& t3) :
        a1_{std::forward<T1>(t1)},
        a2_{std::forward<T2>(t2)},
        a3_{std::forward<T3>(t3)}
    {
    }
 
private:
    A a1_, a2_, a3_;
};
 
template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    std::cout << "1 rreferences\n";
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

 
template<class T, class U>
std::unique_ptr<T> make_unique1(U& u)
{
    std::cout << "1 lreferences \n";
    std::cout << "typeinfo = " << typeid(u).name() << std::endl;
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

template<class T, class U>
std::unique_ptr<T> make_unique1(const U& u)
{
    std::cout << "1 const lreferences \n";
    std::cout << "typeinfo = " << typeid(u).name() << std::endl;
    return std::unique_ptr<T>(new T(u));
}


template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    std::cout << "2 rreferences\n";
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}

template<class T, class... U>
std::unique_ptr<T> make_unique2(U&... u)
{
    std::cout << "2 lreference\n";
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}
 
int main()
{   
    auto p1 = make_unique1<A>(2); // rvalue
    int&& i = 1;
    auto p2 = make_unique1<A>(i); // lvalue
    const int f = 1;
    auto p3 = make_unique1<A>(f);
 
    std::cout << "B\n";
    auto t = make_unique2<B>(2, i, 3);
}
