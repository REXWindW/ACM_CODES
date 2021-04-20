#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 3*114514;
int n,m;
int k[MAXN],c[MAXN];
bool vis[MAXN];
inline void solve(){
    read(n),read(m);
    rep(i,1,n) read(k[i]);//guests
    rep(i,1,m) read(c[i]),vis[i] = 0;//prices
    //c is already sorted
    sort(k+1,k+1+n,greater<int>());
    int now = 1;//the smallest number not used
    ll res=0;
    rep(i,1,n){//the guests
        if(k[i]<=now){
            res+=c[k[i]];//give money
        }
        else{
            res+=c[now];
            now++;
        }
    }
    printf("%lld\n",res);
}

int main(){
    int z;
    read(z);
    while(z--) solve();
}