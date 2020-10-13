

constexpr double pi = 3.1424;

constexpr double get_pi()
{
    return pi;
}
int main()
{
    double radius = 2.1;
    constexpr auto a = get_pi();
    auto area = radius * radius * a;
    return 1;
}
