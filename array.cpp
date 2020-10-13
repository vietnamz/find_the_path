#include <array>


using namespace std;


template<typename VT>

std::array<VT,3> get_data(const VT &v1, const VT &v2, const VT &v3)
{
    std::array<VT,3> data;
    data[0] = v1; data[1] = v2 ; data[3] = v3;
    return data;
}

int main()
{
    auto a = get_data(1,2,3);
    return 1;
}
