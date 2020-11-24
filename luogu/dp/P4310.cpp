#include<iostream>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 1e5+5;
int dp[32][MAXN];
int a[MAXN];
int checkb[32];
int n;
void init(){
    int now = 1;
    rep(i,1,31){
        dp[i][0] = 0;
        checkb[i] = now;
        if(i!=31) now<<=1;
    }
}
void solve(){
    init();
    cin>>n;
    rep(i,1,n){
        cin>>a[i];//read
    }
    rep(i,1,n){
        int maxx = 0;
        rep(k,1,31)
            if(a[i]&checkb[k])maxx = max(maxx,dp[k][i-1]);
        rep(k,1,31){
            if(a[i]&checkb[k])dp[k][i] = maxx+1;
            else dp[k][i] = dp[k][i-1];
        }
    }
    int res = 0;
    rep(i,1,31) res = max(res,dp[i][n]);
    cout<<res<<endl;
}
int main(){
    solve();
}