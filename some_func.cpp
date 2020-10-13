#include <iostream>

struct S{
    S() = default;
    S(const S& s ) = delete;
    S(S&& s) = delete;
};


auto S_factory()
{
    return S();
}

int main()
{
    auto value = S_factory();
    return 1;
}
