#include <iostream>
#include <vector>

using namespace std;

// Don't modify the collection and don;t make a copy of the vector
void print_contents(const vector<int> &vec){
    for(int entry:vec){
        cout << " "<< entry;
    }
    cout<<endl;
}

// Modify the collection and don't make a copy of the vector
void modify_collection(vector<int> &vec){
    
    // Remove last element
    vec.pop_back();

    // At at front
    vec.insert(vec.begin(), 300);
    
}


// Generic function that can print any kind of vector
template<typename T>
void print_vector_stuff_foreach(const vector<T>& inp){
    for(auto item: inp){
        cout << item << " ";
    }
    cout<<endl;
}

template<typename T>
void print_vector_stuff_iterloop(const vector<T>& inp){
    for(auto it = inp.begin(); it!=inp.end(); it++){
        cout << *it << " ";
    }
    cout<<endl;
}

int main(int argc, char **argv){
    // Init with default
    // Prints Hello 3 times
    vector<string> stuff (3,"Hello");
    print_vector_stuff_foreach(stuff);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // Access
    int a = v1[2];
    int b = v1.at(3);

    cout << "Acceess by position "<< a<< " "<< b<< endl;
    
    // Insert at beginning
    v1.insert(v1.begin(), 100);

    // Insert 3 places from start
    v1.insert(v1.begin()+2, 200);

    // Emplace
    v1.emplace(v1.begin()+3, 600);

    // Overrwrite using [] or at()
    v1[3] = 666;
    v1.assign(4, 999);

    // Remove 30
    v1.pop_back();
    
    print_vector_stuff_foreach(v1);
    
    // Resize to 2 elements
    v1.resize(2);

    
    cout <<"Print vector after resize" << endl;
    print_vector_stuff_iterloop(v1);
    
    // clear the vector
    v1.clear();
    cout <<"After clear "<<  v1.size() <<endl;

    // We don't pass & in argument
    // Remove last element
    // modify_collection(v1);
    // print_vector_stuff(v1);

    vector<int> foo =  {1,2,3,4,5};
    for(auto  it = foo.rbegin();it!=foo.rend();++it){
        cout<<*it<<endl;
    }
    
    return 0;
}

/*
    vectors have contigious memory unlike lists
    Iterators for lists are different from those of vectors
    
    emplace() vs insert()
    emplace is more efficient for objects as it avoids copy
    for primitive types, they are same

    vector<int> {3,10} => size 2 vector with elements 3, 10
    vector<int> (4,10) => size 4 vector with elements 10,10,10,10

    Insert in a specific position requres an iterator;

*/