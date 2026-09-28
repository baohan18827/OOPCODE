#include <bits/stdc++.h>
using namespace std;

class Nguoi {
    protected:
        string hoten;
        string namsinh;
        string quequan;

    public:
       Nguoi () {
        hoten="";
        namsinh="";
        quequan="";
       } 
       string GetHoten()  {
            return hoten;
        }

        void SetHoten(string hoten) {
            this->hoten = hoten;
        }

        string GetNamsinh()  {
                return namsinh;
        }

        void SetNamsinh(string namsinh) {
                this->namsinh = namsinh;
        }

        string GetQuequan()  {
                return quequan;
        }

        void SetQuequan(string quequan) {
                this->quequan = quequan;
        }
        ~Nguoi (){

        }
        friend istream& operator >> (istream& is, Nguoi& p) {
            getline(is,p.hoten);
            is>>p.namsinh;
            is.ignore();
            getline(is,p.quequan);
            return is;
        }
        friend ostream& operator << (ostream& os, Nguoi& p) {
            os<<"Ho Ten: "<<p.GetHoten()<<endl<<"Nam Sinh: "<<p.GetNamsinh()<<endl<<"Que quan: "<<p.GetQuequan();
            return os;
        }
};
class SinhVien : public Nguoi {
    protected:
        string khoa;
        vector<int>diem;
    public:
        SinhVien () : Nguoi(), khoa("") {}
        ~SinhVien() {}    
        double diemTB () {
            double tong=0;
            for (int i=0;i<diem.size();i++) {
                tong+=diem[i];
            }
            return tong/diem.size();
        }
        friend istream& operator >> (istream&is, SinhVien& p) {            
            is>>(Nguoi&)p;
            getline(is,p.khoa);
            int x;
            while (is>>x) {
                p.diem.push_back(x);
            }
            return is;
        }
        friend ostream& operator << (ostream& os, SinhVien& p) {
            os<<(Nguoi&)p;
            os<<endl<<"Khoa: "<<p.khoa<<endl<<"Diem cac mon: ";
            for (int i=0;i<p.diem.size();i++) {
                os<<p.diem[i]<<" ";
            }
            os<<endl<<"Diem trung binh: "<<fixed<<setprecision(2)<<p.diemTB();
            return os;
        }
};
int main () {
    SinhVien p;
    cin>>p;
    cout<<p;
}