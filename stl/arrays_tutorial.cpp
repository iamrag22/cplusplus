#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void array_container_example(){

    // Size 10, initialize first 2 values as 0
    array<int, 10> a = {1,2};

    // Fill
    a.fill(5);

    // At
    a.at(9) = 200;

    // First el
    cout << "First el " << a.front()<<endl;

    // Last el
    cout << "Last el " << a.back()<<endl;
    
    // Access Out of bound but does not throw exception but terminates
    // cout << a[100]<< endl;

    // Loop using index
    for(int i=0;i<a.size();i++){
        cout << " "<< a[i];
    }
    cout << endl;

    // Loop using &
    for(auto const &entry : a){
        cout << " "
        << entry;
    }
    cout<<endl;

    // Loop using iter
    // Can also update the collection while iterating
    for(auto it=a.begin(); it<a.end();it++){
        *it = *it+100;
        cout << " "<< *it;
    }
    cout<<endl;

    // After update
    for(auto const &entry : a){
        cout << " "<< entry;
    }
    cout<<endl;

    a[2] = 600;
    a[8]= -1;
    
    //sort 
    sort(a.begin(), a.end());
    for(auto const &item: a){
        cout << " " << item;
    }
    cout<<endl;
}




// void raw_array_print_wrong(int a[]){
//     for(unsigned int i=0;i<sizeof(a)/sizeof(a[0]) ;i++){
//         cout<< a[i] << endl;
//     }

// }

void raw_array_print_correct(int a[], size_t n){
    for(unsigned int i=0;i<n ;i++){
        cout<< a[i] << endl;
    }

}

void raw_array_init(){
    int a[5] = {1,};
    int b[] = {12,13,14};
    int c[6] = {10,20};

    raw_array_print_correct(a,5);
    raw_array_print_correct(b,3);
    raw_array_print_correct(c, 6);
}



int main(int c, char** argv){
    //raw_array_init();
    array_container_example();
    return 0;
}


/*
at() vs [] = > at does a bound check and throws exception. [] does not
*/