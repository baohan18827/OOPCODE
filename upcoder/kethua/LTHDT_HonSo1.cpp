#include <bits/stdc++.h>
using namespace std;

class PhanSo {
    protected:
       int tu;
       int mau;
    public:
        PhanSo () {
            tu=0;
            mau=1;
        }
        PhanSo (int t, int m) {
            tu=t;
            mau=m;
        }    
        PhanSo (const PhanSo& p) {
            tu=p.tu;
            mau=p.mau;
        }
        ~PhanSo () {}
        void nhap () {
            cin>>tu>>mau;
        }
        void xuat () const {
            cout<<tu<<"/"<<mau;
        }
        int getTuSo () const {
            return tu;
        }
        int getMauSo () const {
            return mau;
        }
        PhanSo operator + (const PhanSo &p) const {
            int tuMoi=tu*p.mau+p.tu*mau;
            int mauMoi=mau*p.mau;
            return PhanSo(tuMoi,mauMoi);
        }
};
class HonSo : public PhanSo {
    protected:
        int nguyen;
    public:
        HonSo () :  PhanSo() ,nguyen(0){}
        HonSo (int n, int t, int m) : PhanSo(t,m) ,nguyen(n) {} 
        HonSo (const HonSo& h) : PhanSo(h), nguyen(h.nguyen) {}
        int getNguyen () const {
            return nguyen;
        }
        HonSo operator + (const HonSo& h) const {
             int tuMoi = tu * h.mau + h.tu * mau;
            int mauMoi = mau * h.mau;
            int nguyenMoi = nguyen + h.nguyen;
            return HonSo(nguyenMoi, tuMoi, mauMoi);
        }
        void nhap (){
            cin>>nguyen;
            PhanSo :: nhap();
        }
        void xuat () const {
            cout<<nguyen<<" ";
            PhanSo::xuat();
        }
};
int main () {
    HonSo a;
    HonSo b;
    HonSo c;
    a.nhap();
    b.nhap();
    c=a+b;
    c.xuat();

}