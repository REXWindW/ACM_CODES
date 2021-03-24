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
int a[4],d;
void solve(){
    rep(i,1,3) cin>>a[i];
    cin>>d;
    sort(a+1,a+1+3);
    int res1 = max(a[1]-(a[2]-d),(ll)0);
    int res2 = max(a[2]+d-a[3],(ll)0);
    cout<<res1+res2<<endl;
}

signed main(){
    solve();
}