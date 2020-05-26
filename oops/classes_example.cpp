#include<iostream>
#include<memory>

using namespace std;

class Student{
private:
    string name;
    int age;
    static int count;
public:
    Student(){

    }

    Student(const string& name, const int& age){
        this->name = name;
        this->age = age;
    }
    
    void SetAge(const int&age){
        this->age = age;
    }

    void SetAge(const string& name){
        this->name = name;
    }

    void PrintDetails(){
        cout << name << age << endl;
    }

    ~Student(){

    }
};

unique_ptr<Student> CreateNewStudent(const string& name,const int& age){

    // Option 1
    //return make_unique<Student>(name, age);
    
    // Option 2
    return unique_ptr<Student>(new Student(name, age));
}

// Student& wrong_func(){
//     Student s("ddd", 10);
//     return s;
// }

int main(){
    Student s1("Foo", 10);
    //s1.PrintDetails();

    // Copy the values
    // Changes to s1 wont impact s
    Student s11 = s1;
    s11.SetAge(60); 
    
    // Foo, 10
    s1.PrintDetails();

    // Foo, 60
    s11.PrintDetails();

    Student* s2 = new Student("Bar", 20);

    Student* s5 = new Student{"Hoo", 30};
    s5->PrintDetails();
    //s2->PrintDetails();

    // IMP: delete any memory created on heap; 
    delete s2;

    //Using smart_ptr to create object.No need to handle deallocations.
    auto s3 = CreateNewStudent("Car",30);
    //s3->PrintDetails();

    //auto x = wrong_func();
    

    return 0;
}



/*
Objects can be created on stack or heap
 Use heap if objects are created in functions and we need them outside of the func
 stack has limited memory.So if the objects are huge/a lot them, use heap
 If objects are created on heap, we are responsible for cleaning up  using delete/free 

*/