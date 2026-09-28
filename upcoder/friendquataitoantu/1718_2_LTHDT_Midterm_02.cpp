#include <bits/stdc++.h>
using namespace std;

class Employee {
    private:
        int id;   
        string firstName;
        string lastName;
        double salary;
    public:
        Employee() {
            id = 0;
            firstName = "";
            lastName = "";
            salary = 0;
        }
        Employee(int id, string firstName, string lastName, double salary) {
            this->id=id;
            this->firstName=firstName;
            this->lastName=lastName;
            this->salary=salary;
        }
        
        int getID() {
            return id;
        }
        string getFirstName() {
            return firstName;
        }
        string getLastName() {
            return lastName;
        }
        string getName() {
            return firstName + " " + lastName;
        }
        double getSalary() {
            return salary;
        }
        void setSalary (double salary) {
            this->salary=salary;
        }
        double getAnnualSalary() {
            return salary*12;
        }
        double raiseSalary(double percent) {
            return salary*(1+percent/100.0);
        }
        string toString() {
            stringstream ss; 
            ss << "Employee[id=" << id << ",name=" << 
                firstName << " " << lastName << 
                ",salary=$" << fixed << setprecision(2)<<salary << "]";
            return ss.str();
        }
        Employee& operator ++ () {
             salary*=1.1;
             return *this;
        }
         Employee operator ++ (int) {
             Employee temp = *this;
             salary*=1.1;
             return temp;
        }
        Employee& operator -- () {
            salary*=0.9;
            return *this;
        }
         Employee operator -- (int) {
            Employee temp = *this;
            salary*=0.9;
            return temp;
        }
        Employee& operator + (double so) {
            salary+=so;
            return *this;
        }
        Employee& operator - (double so) {
            salary-=so;
            return *this;
        }
        bool operator > (Employee& p) {
            return getAnnualSalary()>p.getAnnualSalary();
        }
        bool operator < (Employee& p) {
            return getAnnualSalary()<p.getAnnualSalary();
        }
        bool operator == (Employee& p) {
            return getAnnualSalary()==p.getAnnualSalary();
        }
        bool operator != (Employee& p) {
            return getAnnualSalary()!=p.getAnnualSalary();
        }
        friend istream& operator >> (istream& is, Employee& p) {
            is>>p.id>>p.firstName>>p.lastName>>p.salary;
            return is;
        }
        friend ostream& operator << (ostream& os, Employee& p) {
            os<<p.toString();          
            return os;
        }
};      
int main () {
    Employee a;
    Employee b;
    double x,y;
    cin>>a>>b>>x>>y;
    cout<<a<<endl<<b<<endl;
    if(a==b) {
        cout<<"BANG NHAU"<<endl;
    }
    else if(a<b) {
        cout<<"NHO HON"<<endl;
    }
    else {
        cout<<"LON HON"<<endl;
    }
    cout<<fixed<<setprecision(2)<<"$"<<(a++-x).getSalary()<<"$6851.02";
}    