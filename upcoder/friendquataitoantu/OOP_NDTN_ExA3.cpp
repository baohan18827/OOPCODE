#include <bits/stdc++.h>
using namespace std;

class ARRINT1 {
    public:
        int m,n;
        int a[100];
        int b[100];

        void hieu  (ARRINT1 &p) {
            ARRINT1 kq;
            kq.m = max(p.m, p.n); 
            if (p.m<p.n) {
                for (int i=0;i<p.m;i++) {
                    kq.a[i]=p.a[i]+p.b[i];
                    if (kq.a[i]>=10) {
                        kq.a[i]-=10;
                    }
                }
                for (int i=p.m;i<p.n;i++) {
                    kq.a[i]=p.b[i];
                }
            }
            else {
                for (int i=0;i<p.n;i++) {
                    kq.a[i]=p.a[i]+p.b[i];
                    if (kq.a[i]>=10) {
                        kq.a[i]-=10;
                    }
                }
                for (int i=p.n;i<p.m;i++) {
                    kq.a[i]=p.a[i];
                }
            }
            cout<<kq.m<<": ";
            for (int i=0;i<kq.m;i++) {
                cout<<kq.a[i];
            }
        }
        friend istream& operator >> (istream& is, ARRINT1& p) {
            is>>p.m>>p.n;   
             for (int i=p.m-1;i>=0;i--) {
                is>>p.a[i];
            }              
            for (int i=p.n-1;i>=0;i--) {
                is>>p.b[i];
            }
            return is;
        }
}; 
int main () {
    ARRINT1 t;
    cin>>t;
    t.hieu(t);
}