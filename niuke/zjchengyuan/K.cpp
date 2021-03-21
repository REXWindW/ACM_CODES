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

ll dp[301][301][1001];//第几行/多少长/占多少容量
int a[301][301];
ll sum[301][301];
int n,m,k;
inline ll gs()
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n){//前缀和
        rep(j,1,m){
            cin>>a[i][j];
            sum[i][j] = sum[i][j-1]+a[i][j];
        }
    }
    rep(j,1,m){
        dp[n][j][j]=sum[n][j];
    }
    repb(i,n-1,1){//倒着选行
        //类似分组背包
        rep(len,0,m){//这行选几个
            rep(nlen,0,j){//往下一行的长度要小于j
                
            }
        }
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}