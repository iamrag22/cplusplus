#include <iostream>
#include <string>
#include <tuple>
using namespace std;


// Function with default parameters at the end
void default_params_example(int a, const string& message="Hello"){
    cout << a << " " << message <<endl;
}

// Function template
template<typename T, typename U>
auto swap(T& t, T& u){
    T temp(t);
    t = u;
    u = temp;
}

// Function with trailing return type
template<typename T, typename U>
auto Plus(const T& t, const U& u) -> decltype(t+u){
    return t+u;
}

// Function with multiple return type
tuple<int, string, bool> tuple_return_func(){
    int i(10);
    string s("Hello");
    bool b(true);

    return {i,s,b};
}


constexpr float exp(float x,int n){
    if(n==0){
        return 1.0;
    }
    else{
        float y = exp(x,n/2);
        if(n%2==0){
            return y*y;
        }
        else{
            return x*y*y;
        }
    }
}


int main(){
    
    // default_params_example(1);
    // default_params_example(2, "World");

    int a = 1, b = 2;
    swap(a, b);
    cout << "After swap 2 integers "<< a << " " << b <<endl;

    string s1 = "Hello", s2 = "World";
    swap(s1,s2);
    cout << "After swap 2 strings "<< s1 << " " << s2 <<endl;


    // decltype examples
    auto add_ints = Plus(a,b);
    auto add_floats = Plus(1.2,3.4);
    auto add_strings = Plus (s1, s2);
    auto add_int_float = Plus(3.5, 1);
    cout << "Plus function on 2 ints " << add_ints << endl;
    cout << "Plus function on 2 floats " << add_floats << endl;
    cout << "Plus function on 2 strings " << add_strings << endl;
    cout << "Plus function on 1 string and int " << add_int_float << endl; 

    // Functions with multiple return types
    auto t  = tuple_return_func();
    cout << "Result of tuple return func: "<< get<0>(t) << " "<<get<1>(t) << " "<< get<2>(t)<<endl;

    constexpr auto d = exp(7,3);
    cout<<d<<endl;


    return 0;
}