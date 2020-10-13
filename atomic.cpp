// atomic::load/store example
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::memory_order_relaxed
#include <thread>         // std::thread
#include <unistd.h>

std::atomic<int> foo (0);

void set_foo(int x) {  
  sleep(5);
  foo.store(x,std::memory_order_seq_cst);     // set value atomically
}

void print_foo() {
  int x = 22;
  do {
    x = foo.load(std::memory_order_seq_cst);  // get value atomically
    std::cout << "x="<<x <<std::endl;
  } while (x==0);
  std::cout << "foo: " << x << '\n';
}

int main ()
{
  std::thread first (print_foo);
  std::thread second (set_foo,10);
  first.join();
  second.join();
  return 0;
}
