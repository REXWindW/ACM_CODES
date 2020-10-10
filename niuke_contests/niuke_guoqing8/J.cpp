#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define int long long
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define repb(i,a,b) for(ll i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 1e7+5;
int n;
bool isprime[MAXN];
int prim[MAXN];
int cnt;
void init(){
    cnt = 0;
    rep(i,2,n) isprime[i] = 1;
    isprime[0] = isprime[1] = 0;
    rep(i,2,n){
        if(!isprime[i]) continue;
        prim[cnt++] = i;
        for(ll j = i*i;j<=n;j+=i) isprime[j] = 0;
    }
}
signed main(){
    cin>>n;
    init();
    ll res = 0;
    rep(i,1,n){
        int px = lower_bound(prim,prim+cnt,n/i+1)-prim;
        //cout<<i<<' '<<px<<endl;
        res += px*(px-1);
    }
    cout<<res<<endl;
}