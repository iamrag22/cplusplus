#include <iostream>
#include<string>

using namespace std;

class Person{
    void friend SetAge(Person& p,const int& age);
public:
    Person(){}

    Person(const string&name,const int& age): _name{name},_age(age){

    }

    void PrintDetails(void){
        cout <<_age << " "<<  _name << endl;
    } 
private:
    int _age;
    string _name;
};

// Notice that sro operator is not used for definition
void SetAge(Person&p,const int& new_age){
    p._age = new_age;
}


int main(){
    // Default values
    Person p;
    p.PrintDetails();

    // via  constructor
    Person p2("Foo", 20);
    p2.PrintDetails();

    //Call friend function
    SetAge(p2,25);
    p2.PrintDetails();

    return 0;

}