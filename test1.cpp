

#include <iostream>
#include <vector>


using namespace std;

enum class color {
    YELLOW,
    RED,
    BLACK
};

enum class skin {
    BLACK,
    WHITE,
    YELLOW,
};
int main()
{
    color test = color::YELLOW;
    int a = test;
    cout << "a = " << a << endl;
    return 1;
}
