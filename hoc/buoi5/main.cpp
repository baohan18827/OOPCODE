#include<bits/stdc++.h>
#include "student.cpp"
using namespace std;
int Student::sl=0;
int main() {
    Student hs1("Thuan",18,4.0);
    Student hs2("Han",5,1.1);
    hs1.display();
    hs2.display();
    cout<<Student::sl;
}