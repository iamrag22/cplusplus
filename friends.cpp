#include <iostream>
#include <string>

using namespace std;
// Forward declaration required for class
// that would declare  A as its friend
class B;

class A{
public:
    void Print(B&  b);
};

class B{

private:
    int _val;
    // A knows how to print this
    friend void A:: Print(B&);
public:
    B(){}
    B(const int& val): _val(val){}

};

void A::Print( B& b){
    cout << b._val <<endl;
}


class D;

class C{
private:
    int _val1;
    string _val2;
    friend class D;
public:
    C(){};
    C(const int& val1, const string& val2): _val1(val1), _val2(val2){
        
    }

    void GetDetails(void){
        cout << _val1 << " "<< _val2<< " "<<endl;
    }
};

class D{
    public:
        void UpdateStuff(C& c){
            c._val1 = 40;
            c._val2 = "FooBar";
        }
};

int main(){
    //Example where class B friends class A(for specific functions)
    B b(10);
    A a;
    a.Print(b);

    // class D is full friend of class C;
    C c(30, "xyz");
    D d;
    d.UpdateStuff(c);
    c.GetDetails();

    return 0;
}