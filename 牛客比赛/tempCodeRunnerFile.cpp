#include<iostream>
using namespace std;
#define ll long long 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1e6+5;
int n,q;
ll zr,zc,cr,cc;
bool fr[MAXN],fc[MAXN];

int main(){
    cin>>n>>q;
    ll tmp = 0;
    rep(i,1,n){
        tmp+=i;
        fr[i] = fc[i] = 0;
    }
    zr = zc = tmp;
    cr = cc = n;
    char tmpp;
    int hc;
    while(q--){
        cin>>tmpp;
        if(tmpp=='R'){
            cin>>hc;
            if(fr[hc]==1){
                cout<<0<<endl;
                continue;
            }
            fr[hc] = 1;//标记使用
            cout<<zr+(cr*hc)<<endl;
            zc-=hc;
            cc--;
        }
        else{
            cin>>hc;
            if(fc[hc]==1){
                cout<<0<<endl;
                continue;
            }
            fc[hc] = 1;//标记使用
            cout<<zc+(cc*hc)<<endl;
            zr-=hc;
            cr--;
        }
    }
}