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
const int MAXN = 114514*2;
ll a[MAXN];
int n,k;
const ll LINF = 1ll<<60;
inline ll Abs(ll x){return x<0?-x:x;}
void solve(){
    cin>>n>>k;
    rep(i,1,n)
        cin>>a[i];
    sort(a+1,a+1+n);
    ll minn = LINF;
    ll minp = -1;
    rep(i,k+1,n){
        if(minn>a[i]-a[i-k]){
            minn = a[i]-a[i-k];
            minp = (a[i]+a[i-k])/2;
        }
    }
    cout<<minp<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}