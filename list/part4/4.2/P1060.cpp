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
const int MAXN = 5e4+5;
int n,m;
int dp[MAXN];
int v,w;
void solve(){
    cin>>n>>m;
    rep(i,1,m){
        cin>>w>>v;
        repb(i,n,1)
            if(i>=w) dp[i] = max(dp[i-w]+w*v,dp[i]);
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
}