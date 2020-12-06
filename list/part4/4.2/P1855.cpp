//二维费用的01背包
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
const int MAXN = 233;
int dp[MAXN][MAXN];
int n,m,t;
int mi,ti;
void solve(){
    cin>>n>>m>>t;
    rep(i,1,n){
        cin>>mi>>ti;
        repb(i,m,1)
            repb(j,t,1)
                if(i>=mi&&j>=ti) 
                    dp[i][j]=max(dp[i][j],dp[i-mi][j-ti]+1);
    }
    cout<<dp[m][t]<<endl;
}

int main(){
    solve();
}