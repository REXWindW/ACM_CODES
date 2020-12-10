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
const int MAXN = 2e5+5;
int a[MAXN],n;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int maxx = max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
    int tmpx;
    rep(i,2,n-1){
        tmpx = (a[i+1]+a[i-1])>>1;
        maxx = max(maxx,
        abs(a[i+1]-a[i])+abs(a[i-1]-a[i])-(abs(a[i+1]-tmpx)+abs(a[i-1]-tmpx)));
    }
    ll res = 0;
    repb(i,n,2) res+=abs(a[i-1]-a[i]);
    //cout<<"check"<<res<<' '<<maxx<<endl;
    cout<<res-maxx<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}