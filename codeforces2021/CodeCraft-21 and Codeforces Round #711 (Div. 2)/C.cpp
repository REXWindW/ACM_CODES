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
const int med = 1e9+7;
int n,k;
const int MAXN = 1145;
ll dp[MAXN][MAXN];//di的粒子，行进方向上剩余j个平面，一共能生成多少粒子
ll sum[MAXN][MAXN];
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        dp[1][0] = sum[1][0] = 1;
        dp[1][i] = 1;
        sum[1][i] = (sum[1][i-1]+dp[1][i])%med;
    }
    rep(i,2,k){
        dp[i][0]=sum[i][0]=1;
        rep(j,1,n){
            //dp[i][j] = dp[i-1][n-j]+....dp[i-1][n-1]
            dp[i][j] = (sum[i-1][n-1]-sum[i-1][n-j-1]+med+1)%med;
            sum[i][j] = (sum[i][j-1]+dp[i][j])%med;
        }
    }
    /*
    cout<<"check"<<endl;
    rep(i,1,k){
        rep(j,0,n) cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    */
    cout<<dp[k][n]%med<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}