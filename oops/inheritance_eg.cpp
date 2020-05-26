#include <iostream>
#include <string>

using namespace std;

class Base{
public:

    // const/inline static definition is allowed inside class
    const  static int a = 10;
    inline static string greeting1 = "Hello";
    
    
    static string greeting2;

    int id = 100;

    auto GetId(){
        return id;
    }

};

class Derived1: private Base{
public:
    int id2 = 200;
    auto GetId2(){
        return id2;
    }

};

class Derived3: public Derived1{

};
// Traditionally, static members are declared in class but defined outside
string Base::greeting2 ("Hello World");

int main(){

    Derived3 d3;
    cout<< Base::greeting1<<endl;
}