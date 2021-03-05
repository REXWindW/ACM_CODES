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
int n,m,x;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll a[514][514];
void solve(){
    cin>>n>>m;
    ll lcmm = 1;
    rep(i,1,n){
        rep(j,1,m){
            cin>>a[i][j];
            lcmm = lcm(a[i][j],lcmm);
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            if((i+j)%2) cout<<lcmm+a[i][j]*a[i][j]*a[i][j]*a[i][j]<<' ';
            else cout<<lcmm<<' ';
        }
        cout<<endl;
    }
}

int main(){
    solve();
}