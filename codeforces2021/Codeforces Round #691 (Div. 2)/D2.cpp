#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
const int MAXN = 114;
#define INF 0x3f3f3f3f
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
int dp[MAXN][10010];
int a[MAXN],b[MAXN];
int n,tot;
void solve(){
    cin>>n;
    tot = 0;
    rep(i,1,n){
        cin>>a[i]>>b[i];
        tot+=b[i];
    }
    memset(dp,-INF,sizeof(dp));
    dp[0][0]=0;
    rep(i,1,n){
        repb(j,i,1){
            repb(k,tot,0){//错在这里，因为可能有bi=0的情况
                if(k>=b[i]&&j) dp[j][k] = max(dp[j][k],dp[j-1][k-b[i]]+a[i]);
            }
        }
    }
    rep(j,1,n){
        double res = 0;
        rep(k,0,tot){//第二处错在这里，应该从0开始，因为k是水量不是容量，所以也可能为0
            res = max(res,min((double)dp[j][k],k+(double)(tot-k)/2));
        }
        cout<<res<<' ';
    }
    cout<<endl;
}
int main(){
    solve();
}