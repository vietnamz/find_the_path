#include <string>
#include <iostream>

struct Foo{
    Foo(const Foo& other )
    {
        std::cout << "Copy constructor\n";        
    }
    Foo(const Foo&& other)
    {
        std::cout << "Move constructor\n";
    }
    Foo()
    {
        std::cout << "Default constructor\n";
    }
};
Foo get_foo()
{
    const Foo f;
    return f;
}
void do_work()
{
    const std::string str = "Hello World!";
}
std::string get_value()
{
    return std::string{};
}
int main()
{
    const auto value = get_value();
    [[maybe_unused]]const auto t = get_foo();
    return 1;
}
