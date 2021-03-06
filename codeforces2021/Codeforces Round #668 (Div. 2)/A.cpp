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
const int MAXN = 114514;
int a[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    repb(i,n,1) cout<<a[i]<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}