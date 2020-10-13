#include <iostream>
#include <fstream>
using namespace std;


int main() 
{
    cout << "size_t is limted to " << numeric_limits<size_t>::max() << " bytes (" << numeric_limits<size_t>::max() /1024/1024<<" MB)"<< endl;
    cout << "streamsize is limited to " << numeric_limits<streamsize>::max() << " bytes (" << numeric_limits<streamsize>::max() / 1024 / 1024/1024/104 << " TB)" << endl;

    static char mbloc[1024*1024];
    fill_n(mbloc, sizeof(mbloc), 'A');
    const size_t blocs = 3*1024;
    ofstream os("test.out");
    for(int i = 0; i < blocs && os; i++) {
        os.write(mbloc, sizeof(mbloc));
        if(i % 512)
            cout << "tellp() -> " << os.tellp() << "\r";
    }
    cout << endl;
    os.seekp(0, ios::end);
    cout << os.tellp() << " end"<<endl;
    os.close();
    cout << "File generation finished";
    return 0;
}
