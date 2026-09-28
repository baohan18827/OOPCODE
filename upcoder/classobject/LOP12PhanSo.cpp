// #include <bits/stdc++.h>
// using namespace std;
// int UCLN(int a, int b) {
//     while (b!=0) {
//         int r=a%b;
//         a=b;
//         b=r;
//     }
//     return a;
// }
// void rutGon(int &a, int &b) {
//         int c=UCLN(a,b);
//         a=a/c;
//         b=b/c;
//         cout<<a<<"/"<<b<<endl;
// }
// class PhanSo {
//     public:
//         int a,b;

//         void nhap() {
//             cin>>a>>b;
//         }
//         void xuat() {
//             cout<<a<<"/"<<b<<endl;
//         }
//         void tumau() {
//             cout<<a<<endl<<b<<endl;
//         }
//         void nghichDao() {
//             cout<<b<<"/"<<a<<endl;
//         }
//         void rG(){
//             rutGon(a,b);
//         }
            
//         void tong() {
//             int c=a*a+b*b;
//             int d=a*b;
//             rutGon(c,d);
//         }
// };
// int main () {
//     PhanSo p;
//     p.nhap();
//     p.xuat();
//     p.tumau();
//     p.nghichDao();
//     p.rG();
//     p.tong();
// }

#include <bits/stdc++.h>
using namespace std;

class PS {
    private:
        int tu,mau;
    public:
        PS(int _tu=0, int _mau=1) {
            tu=_tu;
            mau=_mau;
        }
        PS (const PS&d) {
            tu=d.tu;
            mau=d.mau;
        }
        int getTu();
        int getMau();
        void setTu(int _tu);
        void setMau(int _mau);
        void nhap();
        void xuat();
        void rutGon();
        PS nghichDao();
        void tong( PS b);
        ~PS() {}
};
int PS::getTu() {
    return tu;
}
int PS::getMau() {
    return mau;
}
void PS::setTu(int _tu) {
    tu=_tu;
}
void PS::setMau(int _mau){
    mau=_mau;
}
void PS::nhap() {
    int _tu,_mau;
    cin>>_tu>>_mau;
    setTu(_tu);
    setMau(_mau);
}
void PS::xuat() {
    cout<<getTu()<<"/"<<getMau()<<endl;
}
void PS::rutGon() {
    int d=__gcd(tu,mau);
    tu=tu/d;
    mau=mau/d;
    if (tu<0) {
        tu=-tu;
        mau=-mau;
    }
    cout<<tu<<"/"<<mau<<endl;
}
PS PS::nghichDao() {
    PS b;
    b.tu=mau;
    b.mau=tu;
    return b;
}
void PS::tong(PS b) {
    PS c;
    c.tu=tu*b.mau+mau*b.tu;
    c.mau=mau*b.mau;
    c.rutGon();
}
int main () {
    PS a,b;
    a.nhap();
    a.xuat();
    cout<<a.getTu()<<endl<<a.getMau()<<endl;
    b=a.nghichDao();
    b.xuat();
    a.rutGon();
    a.tong(b);
}

