#include <iostream>
using namespace std;
class Cat {
    public:
        string name, color;
        int age;
        int* arr;

        Cat(string name, int age, string color) {
            this->name=name;
            this->age=age;
            this->color=color;
            arr=new int[10];
        }

        ~Cat() {
            cout<<"destructor"<<endl;
            delete arr;
        }
    
        void display() {
            cout<<name<<" "<<age<<" "<<color;
        } 
        void makeSound() {
            cout<<endl<<"Gruu gruu"<<endl;
        }
};
