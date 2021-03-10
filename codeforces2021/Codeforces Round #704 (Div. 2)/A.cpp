#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int a[5];
int p;
const ll LINF = 1ll<<62;
void solve(){
    cin>>p;
    rep(i,1,3) cin>>a[i];
    int minn = LINF;
    rep(i,1,3){
        minn = min(minn,(p+a[i]-1)/a[i]*a[i]-p);
    }
    cout<<minn<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}