#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */
long wayOfChange(size_t coinIdx, int coinLeft, vector<long> c ) {
    if ( !coinLeft )
    {
        return 1;
    }
    if( !c.size() )
    {
        return 0;
    }
    if ( coinIdx >= c.size() )
    {
        return 0;
    }
    if ( coinLeft < 0 )
    {
        return 0;
    }
    int currentCoin = c[coinIdx];
    long numWay = 0;
    while( coinLeft >= 0 ) 
    {
        numWay += wayOfChange(coinIdx + 1, coinLeft, c);
        coinLeft -= currentCoin;
    }
    return numWay;
}

long getWays(int n, vector<long> c) {
    //calculate waysi
    /*  
    long numOfWays = 0;
    for( size_t i = 0; i < c.size(); ++i )
    {
        numOfWays += wayOfChange(i, n, c );
    }
    return numOfWays;*/
    return wayOfChange(0, n, c);
}

int main()
{
    ifstream f("test.txt");
    if ( !f.is_open() )
    {
        cout << "Unable to open the test.txt file \n";
        return -1;
    }
    string first_multiple_input_temp;
    getline(f, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(f, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    cout << ways << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

