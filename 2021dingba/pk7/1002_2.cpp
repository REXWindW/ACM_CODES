#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int vis[114514];
int prm[600];
const int MAXX = 1e7;
int mcnt[MAXX];
int n,siz,tmp;
const int med = 1e9+7;
inline ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%med;
        d=d*d%med;c>>=1;
    }return res;
}
inline void init(){
    int sqr = sqrt(MAXX);
    rep(i,2,sqr){
        if(vis[i]) continue;
        prm[siz++] = i;
        for(int j=i+i;j<=sqr;j+=i){
            vis[j] = 1;
        }
    }
    //cout<<"prmsiz"<<prm.size()<<endl;
}
void solve(){
    cin>>n;
    int hc;
    int ma=0;
    rep(i,1,n){
        cin>>hc;
        ma = max(hc,ma);
        for(int i=0;prm[i]*prm[i]<=hc&&i<siz;i++){
            tmp = 0;
            while(hc%prm[i]==0){
                //cout<<prm[i]<<endl;
                hc/=prm[i];
                tmp++;
            }
            mcnt[prm[i]]=max(tmp,mcnt[prm[i]]);
        }
        if(hc>1){
            mcnt[hc] = max(mcnt[hc],1);
        }
    }
    //cout<<"check"<<endl;
    ll res = 1;
    rep(i,2,ma){
        //cout<<"cnt"<<i<<':'<<mcnt[i]<<endl;
        if(!mcnt[i]) continue;
        res*=qpow(i,mcnt[i]);
        res%=med;
    }
    cout<<res<<endl;
}

int main(){
    init();
    solve();
}