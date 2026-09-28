#include <bits/stdc++.h>
using namespace std;

int UCLN (int a, int b) {
    a=abs(a);
    b=abs(b);
    while (b>0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
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
        void rutGon () {
            int d=UCLN(tu,mau);
            tu/=d;
            mau/=d;
            if (mau<0) {
                tu=-tu;
                mau=-mau;
            }
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
              int t1 = tu;
              int t2 = h.tu;
            if (nguyen < 0)   t1 = -abs(tu);
            if (h.nguyen < 0) t2 = -abs(h.tu);
                int tuMoi = t1 * h.mau + t2 * mau;
                int mauMoi = mau * h.mau;
            int nguyenMoi = nguyen + h.nguyen;
            HonSo ketQua (nguyenMoi, tuMoi, mauMoi);
            ketQua.rutGon();
            return ketQua;
        }   
        void rutGon() {
            PhanSo::rutGon();
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