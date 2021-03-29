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
ll n,m,x;
void solve(){
    cin>>n>>m>>x;
    ll l = (x+n-1)/n;
    ll h = (x-1)%n+1;
    //cout<<h<<':'<<l<<endl;
    cout<<(h-1)*m+l<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}