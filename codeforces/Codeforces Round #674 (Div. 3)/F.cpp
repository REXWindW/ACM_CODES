#include<iostream>
#include<cstring>
using namespace std;
 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 2e5+5;
const ll Mod = 1e9+7;
int a[MAXN];
ll dp[MAXN][4];//0记录序列的数量，123记录a，ab，abc的数量
int n;
char hc;
int main(){
    cin>>n;
    rep(i,1,n){
        cin>>hc;
        if(hc=='?') a[i] = 4;//表示这是一个问号
        else a[i] = hc-'a'+1;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    rep(i,1,n){
        if(a[i]==4){
            dp[i][0] = dp[i-1][0]*3;
            dp[i][1] = dp[i-1][1]*3+dp[i-1][0];
            dp[i][2] = dp[i-1][2]*3+dp[i-1][1];
            dp[i][3] = dp[i-1][3]*3+dp[i-1][2];
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+(a[i]==1)*dp[i-1][0];
            dp[i][2] = dp[i-1][2]+(a[i]==2)*dp[i-1][1];
            dp[i][3] = dp[i-1][3]+(a[i]==3)*dp[i-1][2];
        }
        rep(j,0,3) dp[i][j]%=Mod;
        //取模，因为不会出现1e9*1e9这样的乘，所以最后取模也没毛病
    }
    cout<<dp[n][3]<<endl;
}