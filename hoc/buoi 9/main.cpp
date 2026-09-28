#include <bits/stdc++.h>
using namespace std;

class Cat {
    private:
        string kitkat;
    public:
        Cat(string kitkat) {
            this->kitkat = kitkat;
    }
        friend class Fox;
};

class Fox {
    public:
        void display(Cat cat) {
            cout << cat.kitkat << endl;
        }
};

int main () {
    Cat cat ("kitkatttt");
    Fox fox;
    fox.display(cat);
}