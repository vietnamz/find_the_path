#include <thread>
#include <iostream>
#include <unistd.h>


using namespace std;

void foo()
{
    cout << "Foo with thread id "<< this_thread::get_id() << endl;
     sleep(20);
    cout << "foo returning" << endl;
}

void bar(int x )
{
    cout << "Bar with thread id " << this_thread::get_id()  << endl;
    sleep(20);
    cout << "bar returing" << endl;
}
int main()

{
    thread first(foo);

    thread second(bar, 0);
    cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    std::cout << "foo and bar completed.\n";
    return 0;
}
