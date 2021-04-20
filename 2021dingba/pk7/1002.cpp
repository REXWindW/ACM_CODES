#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
const int med = 1e9+7;
inline ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%med;
        d=d*d%med;c>>=1;
    }return res;
}
const int MAXN = 1e7+2;
int mcnt[MAXN];
int n,hc;
int main(){
    read(n);
    int tmp;
    rep(i,1,n){
        read(hc);
        for(int j = 2;j*j<=hc;j++){
            if(hc==1) break;
            tmp = 0;
            while(hc%j==0){
                hc/=j;tmp++;
            }
            mcnt[j] = max(mcnt[j],tmp);
        }
        if(hc) mcnt[hc] = max(mcnt[hc],1);
    }
    ll res=1;
    rep(i,2,MAXN-2){
        if(mcnt[i]) res = res*qpow(i,mcnt[i])%med;
    }
    printf("%lld\n",res);
}