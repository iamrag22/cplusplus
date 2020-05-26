#include<iostream>
#include <map>
using namespace std;

// template<typename T, typename U>
// void print_map_stuff(const map<T,U>& m){

//     for(auto it = m.begin();it!=m.end();it++){
//         cout << it->first<<"-->"<<it->second <<endl;
//     }
// }

// Probably better ways to generalize 
template<typename T>
void print_map_stuff(const T& m){

    for(auto it = m.begin();it!=m.end();it++){
        cout << it->first<<"-->"<<it->second <<endl;
    }
}

int main(){

    // Map container
    map<string,int> m;

    // Add
    m["Hello"] = 1;
    m["World"] = 2;

    // Add via insert
    m.insert(make_pair("Foo", 3));
    m.insert(make_pair("Bar",4));

    // No insert as ""World" exists
    m.insert(make_pair("World",20));

    // Valid Update
    m["World"] = 20;

    
    //print_map_stuff(m);
    cout << "Current size "<< m.size()<<endl;

    // Remove
    m.erase("Hello");
    m.erase("Wo"); // Does not throw

    print_map_stuff(m);

    cout<< "Multi Map stuff "<< endl;

    //Multimap data structure
    multimap<int, int> mm;
    mm.insert(make_pair(1,100));
    mm.insert(make_pair(1,1000));
    mm.insert(make_pair(2,200));
    mm.insert(make_pair(3,300));
    mm.insert(make_pair(4,400));
    mm.insert(make_pair(5,500));
    mm.insert(make_pair(6,600));

    print_map_stuff(mm);

    // Move a subset of elements to a new multimap
    // multimap<int,int> mm_copy(mm.find(2), mm.find(4));

    // for(auto it = mm.find(1); it!=mm.end();it++){
    //     cout << it->first << " "<< it->second << endl; 
    // }
    
    return 0;


}

/*
    Map maintains the sorted order. 
    Does not insert duplicates with insert() method
    Internally uses RB tree
    Map iterators return a pair

    Multi Map


*/