#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// A copy of name is passed. Not the org string
// Updates wont be reflected after the fn returns.
void does_not_update_string(string name){
    name = "Bar";
}

// Ref to orig string is passed.
void update_string(string& name){
    name = "Bar";
}

void reverse_string(string& s){
    auto start = s.begin();
    auto end = s.end();
    while(distance(start,end)>=0){
        // This will miss 1 char
        // swap(*start, *end);
        // start++;
        // end--;

        //correct
        swap(*(start++), *(--end));
    }
}

int main(int argc,char**argv){

    string name ="Foo";

    does_not_update_string(name);
    cout << "After does_not_update_string() "<<name << endl;

    update_string(name);
    cout << "After update_string() "<< name << endl;
   

    name = "Hello";

    //Add character at end
    name.push_back('W');

    // Another way to add character
    name+='j';

    // Add string at end
    name.append("orld");
    cout<<name<<endl;
    
    name += "zrt";
    cout << name <<endl;

    cout<< name.substr(1,4) << endl;

    // Index of first occurence
    cout << name.find('l')<<endl;

    name.pop_back();

    cout <<name << " " << name.size() <<endl;

    for(auto it = name.begin();it<name.end();it++){
        cout << *it << " ";
    }
    cout<<endl;

    
    for(const char c:name){
        cout << c <<" ";
    }
    cout<<endl;

    string x = "Hello";
    reverse_string(x);
    cout << "Reverse after calling reverse_string() "<< x<<endl;

    string y = "World";
    reverse(y.begin(), y.end());
    cout << "Reverse by calling reverse(): "<< y<<endl;

    return 0;
}

/*
 c++ string is mutable unless const is specified
 reverse() from algorithm is inplace reverse
 += is more efficient than s = s+'a' or s = s+ "foo".
  += can be used for both string and character append.
 Use append() to append a new string to the end of string in place
 Use push_back() to append a character to the end of string in place

*/