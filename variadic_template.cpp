#include <array>
#include <typeinfo>
#include <iostream>

template<typename VT, typename... P>
std::array<VT, sizeof...(P)+ 1>get_data(const VT &v1, const P& ...params )
{
    std::cout << "VT type is " << typeid(v1).name()  << std::endl;
    return {v1, params...};
}

int main()
{
    [[maybe_unused]] std::array<double,5> value = get_data(1.2,2.3,3.5,4.0,4.5);
}
