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
const int MAXN = 114;
int a[MAXN];
int vis[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        vis[i] = 0;
        cin>>a[i];
    }
    a[0]=-1;
    sort(a+1,a+1+n);
    rep(i,1,n){
        if(a[i]!=a[i-1]){
            cout<<a[i]<<' ';
            vis[i]=1;
        }
    }
    rep(i,1,n){
        if(!vis[i]) cout<<a[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}