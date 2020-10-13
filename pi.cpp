#include <iostream>

using namespace std;

struct Double_Data{ 
    Double_Data(const std::size_t size )
        : data(new double[3]) {}
    ~Double_Data() {
        delete [] data;
    }
    double * data;
};
const double pi = 3.141593;
double * get_data() {
    double *data = new double[3];
    data[0] = 1.1; data[1] = 2.2; data[2] = 3.3;
    return data;
}

double sum_data(double* data)
{
    const double sum = data[0] + data[1] + data[2];
    delete [] data;
    return sum;
}

int main()
{
    const int i = 5;
    int const j = 6;
    const double radius = 1.5;
    const double  area = pi * radius * radius;
    sum_data(get_data());
    cout << area ;
}
