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
        cout<<a<<"/"<<b<<endl;
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
        }
            
        void tong() {
            int c=a*a+b*b;
            int d=a*b;
            rutGon(c,d);
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
