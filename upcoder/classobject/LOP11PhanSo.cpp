// #include <bits/stdc++.h>
// using namespace std;
// class PhanSo {
//     public:
//         int a,b;

//         void nhap() {
//             cin>>a>>b;
//         }
//         void xuat () {
//             cout<<a<<"/"<<b;
//         }
// };
// int main () {
//     PhanSo p;
//     p.nhap();
//     p.xuat();
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
        PS(PS &d ) {
            tu=d.tu;
            mau=d.mau;
        }
        int getTu();
        int getMau();
        void setTu(int _tmau);
        void setMau(int _mau);
        void nhap() ;
        void xuat() ;
        

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
void PS::setMau(int _mau) {
    mau=_mau;
}
void PS::nhap() {
    int _tu, _mau;
    cin>>_tu>>_mau;
    setTu(_tu);
    setMau(_mau);
}
void PS::xuat() {
    cout<<getTu()<<"/"<<getMau();
}
int main () {
    PS a;
    a.nhap();
    a.xuat();
}