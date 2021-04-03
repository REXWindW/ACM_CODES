#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int c[5];
const int MAXN = 211;
int a[5][MAXN];
ll dp[MAXN][MAXN][MAXN];
void solve(){
    rep(i,1,3) cin>>c[i];
    rep(i,1,3){
        rep(j,1,c[i]) cin>>a[i][j];
        sort(a[i]+1,a[i]+1+c[i],greater<int>());
    }
    ll res = 0;
    rep(i,0,c[1]){//选i个第一种
        rep(j,0,c[2]){//j个第二种
            rep(k,0,c[3]){//k个第三种
                if(i+1<=c[1]&&j+1<=c[2])
                    dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+(ll)a[1][i+1]*a[2][j+1]); 
                if(i+1<=c[1]&&k+1<=c[3])
                    dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+(ll)a[1][i+1]*a[3][k+1]);
                if(j+1<=c[2]&&k+1<=c[3])
                    dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+(ll)a[2][j+1]*a[3][k+1]);
                res = max(res,dp[i][j][k]);
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    solve();
}