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

int n,q;
int a[MAXN];

void solve(){
    cin>>n>>q;
    a[0] = a[n] = -INF;//不能让1和n的两个当成极小值算进去
    ll res = 0;
    rep(i,1,n){ 
        cin>>a[i];
        if(a[i]>a[i-1]&&a[i]>a[i+1]) res+=a[i];//极大值
        else if(a[i]<a[i-1]&&a[i]<a[i+1]) res-=a[i];//极小值
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}