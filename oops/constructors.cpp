#include <iostream>
#include<string>

using namespace std;

class Box{
public:
    // Default constructor
    Box(){};

    Box(int i):length(i), foo(i){
    }

    // Copy Constructor
    Box(const Box& other): length(other.length), width(other.width),height(other.height) {
    }

    // Move constructor
    Box(Box&& expiring)
    
    // Explicit Constructor
    explicit Box(int i, int j, int k ): length(i), width(j), height(k){

    }

    constexpr int GetVolume(){
        return length*width*height;
    }

    void PrintBoxDetails(){
        cout<< "Length "<< length << " Width "<< width << " Height "<< height << " Foo "<< foo <<endl;
    }

private:
    int length{0};
    int width {0};
    int height {0};

    int foo; // Not initialized
};

class Item{
public:
    // disable default constructor
    Item() = delete;

    Item(int a, const string& b): f1(a), f2(b){}

    // Disable copy constructor
    Item(const Item& other) = delete;

    void PrintItemDetails(){
        cout << f1 <<" "<<f2<<endl; 
    }
private:
    int f1;
    string f2;
};

int main(){

    Box b;
    b.PrintBoxDetails();

    Box b1 {1,2,3};
    b1.PrintBoxDetails();

    // Can't call default constructor
    //  Item it;

    //Copy Constructor
    Box b2 = b1;
    b2.PrintBoxDetails();

    Item i1 {1, "Hello"};
    i1.PrintItemDetails();

    // Copy constructor is disabled
    // Item i2 = i1;

}