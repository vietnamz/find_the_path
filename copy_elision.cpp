#include <iostream>  
using namespace std;

class ABC  
{  
public:   
    const char *a;  
     ABC()  
     { cout<<"Constructor"<<endl; }  
    ABC(const char *ptr)  
     { cout<<"Constructor"<<endl; }  
    ABC( ABC& b )
    {
        cout << "conversion constructor\n";
    }
    ABC(const ABC  &obj)  
    { cout<<"copy constructor"<<endl;}  
   // ABC(ABC&& obj)  
   // { cout<<"Move constructor"<<endl; }  
    ~ABC()  
    { cout<<"Destructor"<<endl; }  
};

ABC fun123()  
{ 
    cout << "func123\n";
    ABC obj; 
    cout << "creating a simple opject\n";
    return obj; 
}


ABC xyz123()  
{
    return ABC(); 
}  

int main()  
{  
    //ABC abc;  
   // ABC obj1(fun123());//NRVO  
    ABC obj2(xyz123());//NRVO  
   // ABC xyz = "Stack Overflow";//RVO  
    return 0;  
}
