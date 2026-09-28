#include <bits/stdc++.h>
using namespace std;
int UCLN(int a, int b) {
    while (b!=0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void rutGon(int &a, int &b) {
        int c=UCLN(a,b);
        a=a/c;
        b=b/c;
}
class PhanSo {
    public:
        int a,b;
        PhanSo () {
            a=0;
            b=1;
        }
        PhanSo(int tu, int mau) {
            a=tu;
            b=mau;
        }
        PhanSo (int n) {
            a=n;
            b=1;
        }
        PhanSo(const PhanSo &p) {
            a=p.a;
            b=p.b;
        }
        ~PhanSo () {
        }
        void nhap() {
            cin>>a>>b;
        }
        void xuat() {
            cout<<a<<"/"<<b<<endl;
        }
        void tumau() {
            cout<<a<<endl<<b<<endl;
        }
        void nghichDao() {
            cout<<b<<"/"<<a<<endl;
        }
        void rG(){
            rutGon(a,b);
            cout << a << "/" << b << endl;

        }
            
        void tong() {
            int c=a*a+b*b;
            int d=a*b;
            rutGon(c,d);
            cout << c << "/" << d << endl;

        }
        PhanSo operator+(PhanSo p) {
        PhanSo kq;
        kq.a = a * p.b + p.a * b;
        kq.b = b * p.b;
        rutGon(kq.a, kq.b);
        return kq;
    }

    PhanSo operator-(PhanSo p) {
        PhanSo kq;
        kq.a = a * p.b - p.a * b;
        kq.b = b * p.b;
        rutGon(kq.a, kq.b);
        return kq;
    }

    PhanSo operator*(PhanSo p) {
        PhanSo kq;
        kq.a = a * p.a;
        kq.b = b * p.b;
        rutGon(kq.a, kq.b);
        return kq;
    }

    PhanSo operator/(PhanSo p) {
        PhanSo kq;
        kq.a = a * p.b;
        kq.b = b * p.a;
        rutGon(kq.a, kq.b);
        return kq;
    }

    PhanSo& operator=(const PhanSo &p) {
        a = p.a;
        b = p.b;
        return *this;
    }

    PhanSo& operator+=(PhanSo p) {
        *this = *this + p;
        return *this;
    }

    PhanSo& operator-=(PhanSo p) {
        *this = *this - p;
        return *this;
    }

    bool operator==(PhanSo p) {
        return a * p.b == p.a * b;
    }

    bool operator!=(PhanSo p) {
        return !(*this == p);
    }

    bool operator>(PhanSo p) {
        return a * p.b > p.a * b;
    }

    bool operator<(PhanSo p) {
        return a * p.b < p.a * b;
    }

    bool operator>=(PhanSo p) {
        return a * p.b >= p.a * b;
    }

    bool operator<=(PhanSo p) {
        return a * p.b <= p.a * b;
    }

    PhanSo& operator++() {
        a += b;
        return *this;
    }

    PhanSo& operator--() {
        a -= b;
        return *this;
    }

    friend istream& operator>>(istream &in, PhanSo &p) {
        in >> p.a >> p.b;
        return in;
    }

    friend ostream& operator<<(ostream &out, PhanSo p) {
        rutGon(p.a, p.b);
        out << p.a << "/" << p.b;
        return out;
    }
};
int main () {
    PhanSo p;
    p.nhap();
    p.xuat();
    p.tumau();
    p.nghichDao();
    p.rG();
    p.tong();
}
