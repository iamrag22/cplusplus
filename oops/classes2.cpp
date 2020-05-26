#include<iostream>
#include<string>

using namespace std; 

class Foo{
public:
    int A,B;
    string C;
    
    Foo(){}
    Foo(const int a, const int b, const string& c){
        A = a;
        B = b;
        C = c;
    }
};

void call_by_value(Foo f){
    f.A = 10;
    f.B = 20;
    f.C = "Hello";
}

void call_by_reference(Foo& f){
    f.A = 10;
    f.B = 20;
    f.C = "Hello";
}

int main(){
    Foo f(1,2,"C");
    cout << "Before "<< f.A << " "<< f.B << " "<< f.C<< endl;;
    
    // Example to show that C++ classes are value types be default.
    // Any changes in the called function won't have an effect outside the func
    call_by_value(f);

    cout << "After call_by_value "<< f.A << " "<< f.B << " "<< f.C<< endl;; // Still 1,2, C

    call_by_reference(f);
    cout << "After  call_by_reference "<< f.A << " "<< f.B << " "<< f.C<< endl; // 10, 20, Hello


    Foo f1;
    cout <<  f1.A << " "<< f1.B << " "<< f1.C<< endl;;


}