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
int a[MAXN],maxx[MAXN];
int n;
void solve(){
    cin>>n;
    maxx[0]=0;
    rep(i,1,n){
        cin>>a[i];
        maxx[i] = max(maxx[i-1],a[i]);
    }
    int px = n;
    while(px){
        int p = px;
        while(a[p]!=maxx[p]) p--;
        rep(i,p,px) cout<<a[i]<<' ';
        px = p-1;
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}