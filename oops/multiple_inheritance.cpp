# include <iostream>
# include <string>

using namespace std;

class Vehicle{
public:
    Vehicle(){}
    Vehicle(const string& make, const string& manufacturer): 
    _make(make),
    _manufacturer(manufacturer){

    }
    void PrintDetails(){
        cout << _make << " "<< _manufacturer <<endl;
    }
protected:
    string _make;
    string _manufacturer; 
};

class Car : public virtual Vehicle{
public:
    Car(){}
    Car(const string& make,const string& manufacturer, const string& category):
    Vehicle(make, manufacturer){
        _category = category;
    }

    void PrintCar(){
        cout << "Called From Car";
    }
protected:
    string _category;
};

class ElectricCar : public virtual Vehicle{
public:
    ElectricCar(){}
    ElectricCar(const string& make,const string& manufacturer):
    Vehicle(make, manufacturer){}
    void PrintElectricCar(){
        cout << "Called From Electric Car";
    }
};


class Tesla : public Car, public ElectricCar{
public:
    Tesla(){}
    void PrintTesla(){
        cout<< "Called From Tesla";
    }
};


int main(){

    Car c1 = {"Foo Name", "Foo Manufacturer","Foo Category"};
    c1.PrintDetails();

    ElectricCar ec1 = {"Bar Name", "Bar Manufacturer"};
    ec1.PrintDetails();

    Tesla t1;
    // To call the Vehicle class, make sure that the immediate base classes are
    // qualified as public virtual
    t1.PrintDetails();
    //t1.PrintTesla();



}