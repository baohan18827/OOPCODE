#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Mang {
    private:
        int soLuong;
        T a[1000];
    public:
        Mang () {
            soLuong=0;
        }
        int getSoLuong() {
            return soLuong;
        }
        T& operator [] (int i){
            return a[i];
        }
        friend istream& operator >> (istream& is, Mang<T>& m){
            m.soLuong=0;
            while (is>>m[m.soLuong])
                m.soLuong++;
            return is;
        }
};
class TapSoMoi {
    private:
        int x,y,z,t;
    public:
        TapSoMoi () {
            x=y=z=t=0;
        }
        TapSoMoi (int a, int b, int c, int d) {
            x=a;
            y=b;
            z=c;
            t=d;
        }
        TapSoMoi operator + (const TapSoMoi &m) {
            TapSoMoi kq;
            kq.x=x+m.x;
            kq.y=y+m.y;
            kq.z=z+m.z;
            kq.t=t+m.t;
            return kq;
        }
        bool operator < (const TapSoMoi &m) {
            return x+y+z+t<m.x+m.y+m.z+m.t;
        }
        TapSoMoi operator = (const TapSoMoi &m) {
            x=m.x;
            y=m.y;
            z=m.z;
            t=m.t;
            return *this;
        }
        TapSoMoi operator ++ () {
            x+=1;
            t+=1;
            return *this;
        }
        friend istream& operator >> (istream &is, TapSoMoi &p) {
            is>>p.x>>p.y>>p.z>>p.t;
            return is;
        }
        friend ostream& operator << (ostream &os, const TapSoMoi &p) {
            os<<"[TapSoMoi] "<<p.x<<";"<<p.y<<";"<<p.z<<";"<<p.t<<endl;
            return os;
        }

};
template <typename T>
void xuly (Mang<T> m ) {
    T mx=m[0];
    T tong=m[0];
    for (int i=1;i<m.getSoLuong();i++) {
        if (mx<m[i]) {
            mx=m[i];
        }
        tong=tong+m[i];
    }
    cout<<mx<<endl<<tong;
}
int main() {
    char s;
    cin>>s;
    if (s=='A') {
        Mang<int>a;
        cin>>a;
        xuly(a);
    }
    else if (s=='B') {
        Mang<TapSoMoi>a;
        cin>>a;
        xuly(a);
    }
}
