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
const int MAXN = 1e4+5;
int n,m,w,c;
int dp[MAXN];

void solve(){
    cin>>n>>m;
    rep(i,1,m){
        cin>>c>>w;
        repb(i,n,1)
            if(i>=c) dp[i] = max(dp[i-c]+w,dp[i]);
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
}