#include <iostream>
#include <thread>

using namespace std;
int x,y;
void foo1()
{
    x = 17;
    y = 23;
}

void foo2()
{
    cout << y << endl;
    cout << x << endl;
}

int main()
{
    thread first(foo1);
    thread second(foo2);

    first.join();
    second.join();

    return 0;
}
