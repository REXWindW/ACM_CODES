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

const int MAXN = 114514;
int n,x;
int a[MAXN];
int c[MAXN];
ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d;
        d=d*d;c>>=1;
    }return res;
}
void solve(){
    cin>>n>>x;
    rep(i,1,n) cin>>a[i],c[i] = 0;
    ll minn = INF;
    rep(i,1,n){
        int ai = a[i];
        while(ai%x==0){
            ai/=x;
            c[i]++;
        }
        minn = min((ll)c[i],minn);
    }
    int px = 1;
    ll res = 0;
    while(c[px]>minn&&px<=n){
        res+=(minn+2)*a[px];
        px++;
    }
    while(px<=n){
        res+=(minn+1)*a[px];
        px++;
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}