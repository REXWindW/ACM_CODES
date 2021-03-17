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
int n;
int cnt[MAXN];//数有几个1
int pw[33];
void init(){
    pw[0]=1;
    rep(i,1,30){
        pw[i]=pw[i-1]<<1;
    }
}
inline void solve(){
    read(n);
    int hc;
    ll res = 0;
    rep(i,1,n){
        read(hc);
        rep(j,0,29){
            if(hc&pw[j]) cnt[i]++;
        }
    }
    int cj=0,co=0;
    //cout<<cnt[1]<<' '<<cnt[2]<<endl;
    rep(i,1,n){
        //cout<<cj<<':'<<co<<endl;
        if(cnt[i]&1){//ji
            //看前面的偶数
            res+=co;
            cj++;
        }
        else{
            res+=cj;
            co++;
        }
    }
    printf("%lld\n",res);
}

int main(){
    init();
    solve();
}