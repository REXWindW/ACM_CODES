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

int n;
const int MAXN = 114514;
int a[MAXN];
int b[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int cnt = 0;
    for(int i=2;i<=n;i+=2)
        b[i] = a[++cnt];
    for(int i=1;i<=n;i+=2)
        b[i] = a[++cnt];
    int res = 0;
    rep(i,2,n-1)
        if(b[i]<b[i-1]&&b[i]<b[i+1]) res++;
    cout<<res<<endl;
    rep(i,1,n) cout<<b[i]<<' ';
    cout<<endl;
}

int main(){
    solve();
}