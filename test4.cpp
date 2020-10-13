#include <iostream>
#include <typeinfo>


using namespace std;


struct Base{};

struct Derived : Base {};

struct Poly_Base { virtual void member(){}};

struct Poly_Derived: Poly_Base {};

typedef int my_int_type;

int main()
{

    cout << std::boolalpha;

    cout << "int vs my_int_type: ";
    cout << (typeid(int) == typeid(my_int_type)) << "\n";
    

    // class type
    //
    cout << "Base class vs derive class: ";

    cout << ( typeid(Base) == typeid(Derived) ) << "\n";

    // no polymorphic object
    //
    //
    Base* pBase = new Derived;
    cout << "Base vs *pBase: ";
    cout << (typeid(Base) == typeid(*pBase)) << "\n";


    Poly_Base *poly_base = new Poly_Derived;
    cout << "Poly Base vs *poly_base: ";
    cout << (typeid(Poly_Base) == typeid(*poly_base)) << "\n";
    return 0;
}
