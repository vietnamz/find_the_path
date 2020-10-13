#include <iostream>

using namespace std;

class Foo {
    public:
    explicit Foo(int a) {
        _a = a;
        cout << "convertion constructor\n";
    }
    Foo() {
        cout << "Default constructor\n";
    }
    private:
        int _a;
};

int main()
{
    Foo a = 2.123;
    return 1;
}
