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
int a,b,c;
const int MAXN = 114;
//1100
//gouzao x:100000000和y:1111100000(c-1个0);
int x[MAXN],y[MAXN];
void solve(){
    cin>>a>>b>>c;
    cout<<1;
    rep(i,2,a) cout<<0;
    cout<<' ';
    rep(i,1,b-c+1) cout<<1;
    rep(i,b-c+2,b) cout<<0;
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}