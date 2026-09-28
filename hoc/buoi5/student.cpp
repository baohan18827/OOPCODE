#include <bits/stdc++.h>
using namespace std;

class Student {
    private:
        string name;
        int age;
        double gpa;
    public:
    static int sl;
        Student(string name, int age, double gpa) {
            this->name=name;
            this->age=age;
            this->gpa=gpa;
            sl++;
        }    
        void setName(string name) {
            this->name=name;
        }
        string getName() {
            return this->name;
        }
        void setAge(int age) {
            this->age=age;
        }
        int getAge() {
            return this->age;
        }
        void setGpa(double gpa){
            this->gpa=gpa;
        }
        double getGpa() {
            return this->gpa;
        }
        void display() {
            cout<<name<<" "<<age<<" "<<gpa<<endl;
        }

};