#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,k;
const int MAXN = 3*114514;
int a[MAXN];
int d[MAXN];
void solve(){
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ll res = a[n]-a[1];
    rep(i,2,n) d[i-1] = a[i]-a[i-1];
    sort(d+1,d+1+n-1,greater<int>());
    rep(i,1,k-1) res-=d[i];
    cout<<res<<endl;
}

int main(){
    solve();
}