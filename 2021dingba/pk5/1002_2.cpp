#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 114514*50;
int n,hc;
int cnt,c[3];//数有几个1
ll res;

inline void solve(){
    read(n);
    res = 0;
    c[0]=c[1]=0;
    rep(i,1,n){
        read(hc);
        cnt = 0;
        while(hc){
            cnt^=1;
            hc&=(hc-1);
        }
        res+=c[cnt^1];
        c[cnt]++;
    }
    printf("%lld\n",res);
}

int main(){
    solve();
}