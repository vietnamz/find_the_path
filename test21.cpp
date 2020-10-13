#include <vector>
#include <algorithm>

using namespace std;


void process_more(const vector<double>& );

void process_data(const vector<double> &values)
{
    const auto in_range  = [](const double d) {
        return d >= 5.0 && d <= 100.0;
    };
    const bool all_in_range = all_of(begin(values), end(values), in_range);
    if ( all_in_range )
    {
        process_more(values);
    }
}

void process_more(const vector<double>& values)
{

}

int main()
{
    process_data(vector<double>());
}
