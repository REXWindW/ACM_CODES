#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}
string a,b;
int n,m;
const int MAXN = 5005;
int dp[MAXN][MAXN];
int res;
void solve(){
    res = 0;
    cin>>n>>m;
    cin>>a>>b;
    rep(i,1,n){
        rep(j,1,m){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+2;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1])-1;
            dp[i][j] = max(dp[i][j],0);
            res = max(res,dp[i][j]);
        }
    }
    cout<<res<<endl;
}
int main(){
    solve();
}