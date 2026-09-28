#include <bits/stdc++.h>
using namespace std;

class HinhHoc {
    public:
        virtual float ChuVi()=0;
        virtual void Nhap()=0;
        virtual ~HinhHoc() {}
};
class HinhVuong: public HinhHoc {
    private:
        float canh;
    public:
        void Nhap() override {
            cin>>canh;
        }
        float ChuVi() override {
            return canh*4;
        }
};
class HinhChuNhat:public HinhHoc {
    private:
        float dai,rong;
    public:
        void Nhap() override {
            cin>>dai>>rong;
        }
        float ChuVi() override {
            return 2*(dai+rong);
        }
};
int main () {
    int n=0;
    HinhHoc* a[100];
    char c;
    while(cin>>c) {
        if (c=='a') {
            a[n]=new HinhVuong();
        }
        else if (c=='b') {
            a[n]=new HinhChuNhat();
        }
        a[n]->Nhap();
        n++;
    }
    for (int i=0;i<n;i++) {
        cout<<a[i]->ChuVi()<<endl;
    }
}