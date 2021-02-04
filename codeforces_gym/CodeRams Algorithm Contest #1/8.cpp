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

const int MAXN = 1145;
ll sum[MAXN][MAXN];
ll a[MAXN][MAXN];

void solve(){
    cin>>n;
    rep(i,1,n){
        sum[i][0]=0;
        rep(j,1,m){
            cin>>a[i][j];
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        }
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}