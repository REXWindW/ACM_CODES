#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
inline ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
inline ll lcm(ll a,ll b){ return a/gcd(a,b)*b;}
//#define INF 0x7fffffff
const int MAXN = 2020;
int lcs[MAXN][MAXN];//lcs
int dp[MAXN][MAXN];
int smallx[MAXN][MAXN];//y在i时第一个比y小的j
string x,y;
int sx,sy;
inline int cal(int i,int j){
    return sx-i+sy-j;
}
inline void init(){
    smallx[sy][sx] = 0;
    rep(i,0,sy-1){
        smallx[i][sx] = sy-i;
        repb(j,sx-1,0){
            smallx[i][j] = smallx[i][j+1];//传递
            if(y[i]>x[j]) smallx[i][j]=cal(i,j);//更新
        }
    }
    rep(i,0,sy) dp[i][sx] = sy-i;
    rep(j,0,sx) dp[sy][j] = 0;
    repb(i,sy-1,0){
        repb(j,sx-1,0){
            dp[i][j] = max(smallx[i][j],dp[i+1][j]);
            dp[i][j] = max(dp[i][j],dp[i][j+1]);
        }
    }
}
inline void solve(){
    lcs[0][0]=lcs[0][1]=lcs[1][0]=0;
    sx = x.size();
    sy = y.size();
    rep(i,0,sx-1){//n方先求出最长公共子序列
		rep(j,0,sy-1){
			if(x[i]==y[j]) lcs[i+1][j+1]=lcs[i][j]+1;
            else lcs[i+1][j+1]=max(lcs[i+1][j],lcs[i][j+1]);
		}
	}
    init();
    int maxx = 0;
    maxx = dp[0][0];
    rep(i,0,sx-1){
        rep(j,0,sy-1){
            //cout<<i<<' '<<j<<':'<<2*lcs[i+1][j+1]<<' '<<dp[i+1][j+1]<<endl;
            maxx = max(maxx,2*lcs[i+1][j+1]+dp[j+1][i+1]);
        }
    }
    cout<<maxx<<endl;   
}
int main(){
    while(cin>>x>>y) solve();
}