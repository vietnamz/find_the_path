#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(string);


bool allEqual(const vector<int>);
// Complete the equal function below.
int equal(vector<int> arr) {
    cout << "-----begin-----" << endl;
    for( const auto& elem : arr )
    {
        cout << "elem = " << elem << endl;
    }
    const int& minValue = *(min_element(arr.begin(), arr.end()));
    cout << "Min value = " << minValue << endl;
    vector<int> possibilies(4);
    for(int i = 0; i < possibilies.size(); ++i)
    {
        int operation = 0;
        for( int j = 0 ; j < arr.size(); ++j )
        {
            int x = arr[j] - ( minValue - i );
            operation += x / 5 + (x % 5) / 2 + (x % 5) % 2;
        }
        cout << "operation = " << operation << endl;

        possibilies[i] = operation;
    }
    return *(min_element(possibilies.begin(), possibilies.end()));
}






int main()
{
    ifstream f("equal.txt");
    if ( !f.is_open() )
    {
        cout << "Unable to open the equal.txt file \n";
        return -1;
    }
    int t;
    f >> t;
    f.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "t=" << t << endl;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        f >> n;
        f.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "n = " << n << endl;
        string arr_temp_temp;
        getline(f, arr_temp_temp);
        cout << "arr_temp_tempt = " << arr_temp_temp << "\n";

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        cout << result << "\n";
    }
    f.close();

    return 0;

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
