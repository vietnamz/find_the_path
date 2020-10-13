#include <filesystem>
#include <iostream>

using namespace std;

enum class E {
    EE, FF, GG
};
class Foo {
    public:
        Foo() = default;
        static int b;
    private:
        static int c;
};
int f() {
    [[maybe_unused]] static int a = 5;
    return 1;
}
using namespace std::__fs::filesystem;
int main()
{
    path p = current_path();
    path p2  = current_path();
    if ( p.is_absolute() )
    {
        std::cout << "this is absolute " << p << "\n";
    }
    return 1;
}
