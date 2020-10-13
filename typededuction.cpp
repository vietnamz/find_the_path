/*
 * 
 *
 * 6 rule type deduction
 *
 * 98:
 *  T&/T*
 *
 * 11:
 *  T&&
 *  
 */

template <typename T>
class TD;


template<typename T>
void f(T&& param)
{
    TD<T> tType;
    TD<decltype(param)> paramType;
}

int main(){
    int x = 22;
    int&& rx = x;
    f(rx);
    return 1;
}
