#include <bits/stdc++.h>
using namespace std;

class KhachHang {
    protected:
        string ten;
        double thoigian;
        int somay;
        static double dongia;
    public:
        KhachHang () : ten(""), thoigian(0), somay(0) {}
        KhachHang(string t, double tg, int so) : ten(t), thoigian(tg), somay(so) {};
        KhachHang(const KhachHang &p) : ten(p.ten), thoigian(p.thoigian), somay(p.somay) {};
        static void setDonGia (double dg) {
            dongia=dg;
        }
        void nhapChung () {
            cin.ignore();
            getline(cin,ten);
            cin>>thoigian>>somay;
        }
        void xuat () {
            cout<<"Ho Ten: "<<ten<<endl;
            cout<<"Thoi gian su dung: "<<thoigian<<endl;
            cout<<"So may: "<<somay<<endl;
        }
        virtual void nhapRieng(){}
        virtual string loaiKhach () =0;
        virtual double tinhTien () =0;
};
double KhachHang::dongia=0;

class KhachVip : public KhachHang  {
    protected:
        static double dongiaVip;
    public:
        KhachVip(): KhachHang() {};
        KhachVip(string t, double tg, int sm): KhachHang(t,tg,sm){};
        KhachVip(const KhachVip& p) : KhachHang(p){};
        static void setdongiaVip (double dg) {
            dongiaVip=dg;
        }
        string loaiKhach() override {
            return "VIP";
        }
        double tinhTien() override {
            if (thoigian>=4) 
                return dongiaVip*4;
            else
                return dongia*thoigian;
        }
};
double KhachVip::dongiaVip=0;
class KhachThuongXuyen: public KhachHang {
    protected:
        double hesokhuyenmai;
    public:
        KhachThuongXuyen(): KhachHang(), hesokhuyenmai(0) {};
        KhachThuongXuyen(string t, double tg, int sm, double hs): KhachHang(t,tg,sm) , hesokhuyenmai(hs) {};
        KhachThuongXuyen(const KhachThuongXuyen& p, double hs): KhachHang(p) , hesokhuyenmai(hs){};
        void nhapRieng() override {
            cin>>hesokhuyenmai;
        }
        string loaiKhach() override {
            return "TX";
        }
        double tinhTien() override {
            return thoigian*dongia-thoigian*hesokhuyenmai;
        }
};
class KhachKhongThuongXuyen: public KhachHang {
    protected:
        double dungluongdownload;
        static double dongiadownload;
    public:
        KhachKhongThuongXuyen() : KhachHang(), dungluongdownload(0) {};
        KhachKhongThuongXuyen(string t, double tg, int sm, double dl) : KhachHang(t,tg,sm), dungluongdownload(dl) {};
        KhachKhongThuongXuyen(const KhachKhongThuongXuyen& p, double dl): KhachHang(p), dungluongdownload(dl) {};
        void nhapRieng() override {
            cin>>dungluongdownload;
        }
        static void setdongiadownload (double dg) {
            dongiadownload=dg;
        }
        string loaiKhach() override {
            return "KTX";
        }
        double tinhTien() override {
            return thoigian*dongia+dungluongdownload*dongiadownload;
        }
};
double KhachKhongThuongXuyen:: dongiadownload=0;
int main () {
    int n;
    double dg,dgv,dgdl;
    cin>>n>>dg>>dgv>>dgdl;
    KhachHang::setDonGia(dg);
    KhachVip::setdongiaVip(dgv);
    KhachKhongThuongXuyen::setdongiadownload(dgdl);
    KhachHang *ds[100];
    string s;
    for (int i=0;i<n;i++) {
        cin>>s;
        if (s=="VIP") {
            ds[i]= new KhachVip();
        }
        else if (s=="TX") {
            ds[i]= new KhachThuongXuyen();
        }
        else {
            ds[i]= new KhachKhongThuongXuyen();
        }
        ds[i]->nhapChung();
        ds[i]->nhapRieng();     
    }
    for (int i=0;i<n;i++) {
        cout<<i+1<<". Loai khach: "<<ds[i]->loaiKhach()<<endl;
        ds[i]->xuat();
        cout<<"So tien phai tra: "<<(int)ds[i]->tinhTien()<<endl;
    }
}
