#include <bits/stdc++.h>
using namespace std;

class Diem {
    private:
        double mang[100];
        int soluong;
    public:
        Diem (){
            soluong=0;
        }
        Diem (int n) {
            soluong=n;
            for (int i=0;i<n;i++)  
                mang[i]=0;
        }
        Diem (const Diem &d) {
            soluong=d.soluong;
            for (int i=0;i<soluong;i++) 
                mang[i]=d.mang[i];
        }
        ~Diem () {

        }
        int getSoluong () {
            return soluong;
        }
        double getDiem(int i) {
            return mang[i];
        }
        void setDiem(int i, double giaTri) {
            mang[i]=giaTri;
        }
        double &operator[] (int i) {
            return mang[i];
        }
        Diem &operator = (Diem &d) {
            soluong=d.soluong;
            for (int i=0;i<soluong;i++) 
                mang[i]=d.mang[i];
            return *this;
        }
        double trungBC () {
            double tong=0;
            for (int i=0;i<soluong;i++) {
                tong+=mang[i];
            }
            return tong/soluong;
        }
        friend istream& operator >> (istream& is, Diem& d) {
            string dong;
            getline(is,dong);
            stringstream ss(dong);
            d.soluong=0;
            double x;
            while (ss>>x) {
                d.mang[d.soluong]=x;
                d.soluong++;
            }
            return is;
        }    
};
class SinhVien {
    public:
        string hoten;
        string mssv;
        Diem d;
        double trungBinhCong () {
            return d.trungBC();
        }
        SinhVien& operator = ( SinhVien &p) {
            hoten=p.hoten;
            mssv=p.mssv;
            d=p.d;
            return *this;
        }
        bool operator < (SinhVien &p) {
            return trungBinhCong()<p.trungBinhCong();
        }
        friend istream& operator >>(istream &in, SinhVien& p) {
           
            getline(in,p.hoten);
            getline(in,p.mssv);
            in>>p.d;
            return in;
        }
        friend ostream& operator << (ostream &on, SinhVien& p) {
            on<<"Ho Ten: "<<p.hoten<<endl<<"Ma Sinh Vien: "<<p.mssv<<endl<<"DTB: "<<fixed<<setprecision(1)<<p.trungBinhCong();
            return on;
        }
};
class MangSinhVien {
    public:
        SinhVien p[100];
        int soSV;
        friend istream& operator >> (istream& is, MangSinhVien &m) {
            is>>m.soSV;
            is.ignore();
            for (int i=0;i<m.soSV;i++) {
                is>>m.p[i];
            }
            return is;
        }
        friend ostream& operator << (ostream& os, MangSinhVien &m) {
            SinhVien mx=m.p[0];
            for (int i=1;i<m.soSV;i++) {
                if (mx<m.p[i]) {
                    mx=m.p[i];
                }
            }
            os<<mx;
            return os;
        }
};
int main () {
    MangSinhVien p;
    cin>>p;
    cout<<p;
}

