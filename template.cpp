#include <cstddef>
#include <iostream>

using namespace std;

template<typename Value_Type>
struct Data {
    Data(const std::size_t size )
        : data( new Value_Type[size]) {
            cout << "constructor\n";            
        }
    ~Data() {
       cout << "Destructor\n"; 
       delete [] data;
    }
    Value_Type *data;
};

template<typename Value_Type>
Data<Value_Type> get_data(const Value_Type &v1, const Value_Type &v2,
                          const Value_Type &v3)
{
    Data<Value_Type> d(3);
    d.data[0] = v1; d.data[1] = v2; d.data[2] = v3;
    cout << hex << d.data << endl;
    return d;
}

int main()
{
    Data<int> d = get_data(1,2,3);
    cout << hex << d.data << endl;
    return 1;
}
