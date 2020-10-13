#include <iostream>


using namespace std;



class Foo {
    public:
    Foo(){};
    Foo(int a, int b) { _a = a; _b=b; };

    bool operator==(const Foo& other) {
        return other._a == this->_a && other._b == this->_b;
    };

    Foo& operator+(const Foo& other)
    {
        this->_a = this->_a + other._a;
        this->_b = this->_b + other._b;
        return *this;
    };
    Foo& operator-(const Foo& other)
    {
        this->_a = this->_a - other._a;
        this->_b = this->_b - other._b;
        return *this;
    }
    Foo& operator++(const int i)
    {
        this->_a = this->_a + 1;
        this->_b = this->_b + 1;
        return *this;
    }
    /* 
    Foo& operator+(const Foo& otherA, const Foo& otherB)
    {
        Foo f;
        f._a = otherA._a + otherB._a;
        f._b = otherB._b + otherB_.b;
        return f;
    }*/
    friend ostream& operator<<(ostream& os, Foo f);
    private:
        int _a, _b;
};

ostream& operator<<(ostream& os, Foo f)
{
    os << f._a << " " << f._b << "\n";
    return os;
}

int main()
{
    Foo a(2,3);
    Foo b(4,5);

    Foo c = a + b;
    cout << c;
    return 0;
}
