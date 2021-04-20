#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
#define int ll
const int MAXN = 2019;
int a[MAXN];
int n;
ll mem[MAXN][MAXN];//分别代表左右端点
ll dfs(int l,int r){
    //cout<<"check"<<l<<' '<<r<<endl;
    if(l==r) return 0;
    if(mem[l][r]) return mem[l][r];
    ll dl = dfs(l+1,r);
    ll dr = dfs(l,r-1);
    return mem[l][r] = min(dl,dr)+a[r]-a[l];
}
inline void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,n);
    cout<<mem[1][n]<<endl;
}

signed main(){
    solve();
}