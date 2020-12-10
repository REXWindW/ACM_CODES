#include<bits/stdc++.h>
using namespace std;
#define ll __int128
const int N=1e5+5;
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
template<class T>
inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
template<class T>
void wt(T x){//快写
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
ll x[N],y[N];
ll cal(int n){
    ll res = 0;
    for(int i=2;i<=n;i++){
        res+=(x[i]*y[i-1]-y[i]*x[i-1]);
    }
    res+=(x[1]*y[n]-y[1]*x[n]);
    if(res<0) res = -res;
    return res;
}
void solve(int n){
    rep(i,1,n){
        read(x[i]);
        read(y[i]);
    }
    ll res = cal(n);
    wt(res/2);
    if(res%2==0) printf(".00\n");
    else printf(".50\n");
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) solve(n);
}
