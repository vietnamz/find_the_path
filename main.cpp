#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the shortestPath function below.
 */
vector<int> shortestPath(vector<vector<int>> a, vector<vector<int>> queries) {
    /*
     * Write your code here.
     */
     
    return     vector<int>();
}

int main()
{

    ifstream testfile ("test.txt");
    if ( !testfile.is_open() )
    {
        cout << "unable to open the text file \n";
        return -1;
    }
    string nm_temp;
    getline(testfile, nm_temp);
    cout << nm_temp << endl;

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(m);

        for (int a_column_itr = 0; a_column_itr < m; a_column_itr++) {
            testfile >> a[a_row_itr][a_column_itr];
        }

        testfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int q;
    testfile >> q;
    testfile.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(4);

        for (int queries_column_itr = 0; queries_column_itr < 4; queries_column_itr++) {
            testfile >> queries[queries_row_itr][queries_column_itr];
        }

        testfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = shortestPath(a, queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";


    return 0;
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
