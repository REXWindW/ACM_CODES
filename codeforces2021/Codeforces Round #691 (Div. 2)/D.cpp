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
int n,tota,totb;
void solve(){
    cin>>n;
    tota = totb = 0;
    rep(i,1,n){
        cin>>a[i]>>b[i];
        tota+=a[i];
        totb+=b[i];
    }
    memset(dp,-INF,sizeof(dp));
    dp[0][0]=0;
    rep(i,1,n){
        repb(j,i,1){
            repb(k,tota,0){
                if(k>=a[i]&&j) dp[j][k] = max(dp[j][k],dp[j-1][k-a[i]]+b[i]);
            }
        }
    }
    rep(j,1,n){
        double res = 0;
        rep(k,0,tota){
            if(dp[j][k]>=0){
                res = max(res,min((double)k,(double)dp[j][k]+(double)(totb-dp[j][k])/2));
            }
        }
        cout<<res<<' ';
    }
    cout<<endl;
}
int main(){
    solve();
}