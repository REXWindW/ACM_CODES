#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1145;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
void solve(){
    int n;
    cin>>n;
    dp[0][0]=dp[0][1]=0;
    rep(i,1,n){
        rep(j,1,i){
            cin>>a[i][j];
            dp[i][j]=a[i][j];
            if(j!=i) dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
            if(j!=1) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+a[i][j]);
        }
    }
    int res = 0;
    rep(i,1,n){
        res = max(res,dp[n][i]);
    }
    cout<<res<<endl;
}

int main(){
    solve();    
}