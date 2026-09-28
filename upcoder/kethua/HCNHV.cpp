#include <bits/stdc++.h>
using namespace std;

// class HinhChuNhat {
//     private:
//         double chieuDai;
//         double chieuRong;
//     public:
//         HinhChuNhat () {
//             chieuDai=0;
//             chieuRong=0;
//         }
//         HinhChuNhat(double d, double r) {
//             chieuDai=d;
//             chieuRong=r;
//         }
//         double GetChieuDai() const {
//             return chieuDai;
//         }

//         void SetChieuDai(double chieuDai) {
//             chieuDai = chieuDai;
//         }

//         double GetChieuRong() const {
//             return chieuRong;
//         }

//         void SetChieuRong(double chieuRong) {
//             chieuRong = chieuRong;
//         }
//         double tinhChuVi () {
//             return (chieuDai+chieuRong)*2;
//         }
//         double tinhDienTich () {
//             return chieuDai*chieuRong;
//         } 
// };
// class HinhVuong : public HinhChuNhat {
//     public:
//         HinhVuong () {

//         }
//         HinhVuong (double canh) : HinhChuNhat (canh,canh) {

//         }
// };
// int main () {
//     string hinh;
//     cin>>hinh;
//     double mx=INT_MIN;
//     if (hinh=="HCN") {
//         double d,r;
//         while (cin>>d>>r) {
//             HinhChuNhat hcn(d,r);
//             double cv= hcn.tinhChuVi();
//             if (cv>mx) {
//                 mx=cv;
//             }
//         }
//     }
//     else {
//         if (hinh=="HV") {
//         double c;
//         while (cin>>c) {
//             HinhVuong hv(c);
//             double cv= hv.tinhChuVi();
//             if (cv>mx) {
//                 mx=cv;
//             }
//         }
//     }
//     }
//     cout<<mx;
// }









// Tính thừa kế:
// có 2 loại: đơn,bội

class HCN {
    int dai, rong;
    public:
        //get-set
        void getDai () {
            cout<<dai<<endl;
        }
        void getRong () {
            cout<<rong<<endl;
        }
        void setDai (int _dai) {
            dai=_dai;
        }
        void setRong (int _rong) {
            rong=_rong;
        }
        
        HCN(int _dai=0,int _rong=0) {
            cout<<"HCN duoc tao"<<endl;
            dai=_dai;rong=_rong;
        }

        HCN(const HCN&h){
            cout<<"HCN duoc tao"<<endl;
            dai=h.dai;rong=h.rong;
        }
        int DT() {
            return dai*rong;
        }
        ~HCN() {
            cout<<"HCN bi huy"<<endl;
        }
};
class HV: public HCN {
    int canh;
    public:
        HV(int _canh=1):HCN(_canh,_canh) {
            canh=_canh;
        }
        HV(const HV&h):HCN(h) {
            cout<<"HV duoc tao"<<endl;
            canh=h.canh;
        }
        int DT() {
            return canh*canh;
        }
        
};
int main () {

}