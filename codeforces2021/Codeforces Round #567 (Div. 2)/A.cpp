#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
#define int ll
int x,y,z;
void solve(){
    cin>>x>>y>>z;
    int ma = (x+y)/z;
    int mx = x/z;
    int my = y/z;
    int mi;
    if(mx+my==ma) mi = 0;
    else mi = min((mx+1)*z-x,(my+1)*z-y);
    cout<<ma<<' '<<mi<<endl;
}

signed main(){
    solve();
}