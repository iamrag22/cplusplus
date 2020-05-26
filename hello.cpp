#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

struct Point{
    int x,y;
};

void print_data_types(){
    int a = 10;
    cout<< "Integer " << sizeof(a) <<endl;  //4 bytes

    short int si = 10;
    cout<< "Short Integer " << sizeof(si) <<endl; //2 bytes

    
    long int c  = 1234567;
    cout << "Long " << sizeof(c) << endl; // 4  bytes

    unsigned long ul = -1234567;
    cout << "Unsigned Long " << sizeof(ul) << endl; // 4  bytes

    long long int lli = 10;
    cout<< "Long Long Integer " << sizeof(lli) <<endl; //8 bytes

    
    char b = 'x';
    cout << "Character "<< sizeof(b) <<endl; //1 byte


    float d  = 3.14f;
    cout << "Float " << sizeof(d) << endl; //4bytes

    double e  = 3.14;
    cout << "Double " << sizeof(e) << endl; // 8 bytes

    bool foo = true;
    cout << "Boolean " << sizeof(foo) <<endl; // 1byte
}


void cin_out_example(){
    string first_name,last_name;
    cout << "Enter first name "<<endl;
    cin >> first_name; // Take input from user
    cout << "Enter last name "<<endl;
    cin >> last_name;  // Take input from user

    string name = first_name + last_name;
    cout<< "Full Name " << name << endl;
}


void string_operations(){


    
    // C style strings
    const char * foo = "Whatddup";
    cout << foo << endl;

    // ISO C++ forbids converting a string constant to 'char*
    // char *bar  = "hlpdf";   // C++ will complain 

    // string as char array
    char name[] = {'S', 'u', 'p'};
    name[1] ='T';
    cout << name << endl;


    // C++ string
    string a  = "Hello";
    cout << a[0] << endl;
    cout << a.back() <<endl; // last char
    
    // Copy first 2 chars of a to b
    string b(a,3); 
    cout<< b << endl;

    // Copy range of characters from a
    string c(a, 2, 5);
    cout << c << endl;

    // c++ strings are mutable
    string x  = "foo";
    x ="bar"; // x is updated
    cout << x <<endl;

    string together = a+x;
    // cout << together << endl;
}
void pointers_intro(){
    int a = 100;
    int * ptr = &a;
    *ptr = 200;
    cout<< a<< endl;

}

int main(int argc, char ** argv ){
    array<int, 3> ax = {};
    for(auto it = ax.begin(); it!=ax.end();it++){
        cout << " "<< *it << endl;
    }
    return 0;

    Point p = {3,4};
    cout << p.x<<p.y<<endl;

    cout << "Hello" <<endl;
    cout<<"World" <<endl;
    vector<string> names = {"foo", "bar", "baz"};

    for(const string& name: names){
        cout <<name <<endl;
    }

    char va = 65;
    cout << va <<endl;

    // print_data_types();
    // pointers_intro();

    // Format
    printf("%c %10d %.3f %s", 'A', 3456789111111, 1.23456, "Hello Universe");
    
    //string_operations();

    
}

