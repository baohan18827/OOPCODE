#include <bits/stdc++.h>
using namespace std;

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
int main () {
    TapSoMoi m,n,tong,cong;
    cin>>m>>n;
    cout<<m<<n;
    if (m<n) cout<<"true"; else cout<<"false";
    cout<<endl;
    tong=m+n;
    cout<<tong;
    cong=++m;
    cout<<cong;
}