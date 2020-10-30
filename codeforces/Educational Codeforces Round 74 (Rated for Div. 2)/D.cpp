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
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
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
const int MAXN = 1e6+5;
int n;
char a[MAXN];
void solve(){
    cin>>n;
    ll res = (ll)n*(n-1)/2;//先假设所有的都可以
    rep(i,1,n) cin>>a[i];
    int px = 2;
    while(a[px]==a[px-1]) px++;
    while(px<=n){
        int cnt = 1;
        px++;
        while(px<=n&&a[px]==a[px-1]){
            cnt++;px++;
        }
        res-=cnt;
    }
    reverse(a+1,a+1+n);
    px = 2;
    while(a[px]==a[px-1]) px++;
    while(px<=n){
        int cnt = 0;//不能重复减去AB这样的，之前的循环已经做过了
        px++;
        while(px<=n&&a[px]==a[px-1]){
            cnt++;px++;
        }
        res-=cnt;
    }
    cout<<res<<endl;
}
int main(){
    solve();
}