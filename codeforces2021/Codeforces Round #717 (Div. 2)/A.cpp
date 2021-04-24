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
const int MAXN = 114514;
int a[MAXN];
int n,k;
void solve(){
    cin>>n>>k;
    rep(i,1,n){
        cin>>a[i];
    }
    int jian;
    rep(i,1,n-1){
        jian = min(a[i],k);
        a[i]-=jian;
        a[n]+=jian;
        k-=jian;
    }
    rep(i,1,n) cout<<a[i]<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}