#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
const int MAXN = 2020;
string x,y;
int smallx[MAXN][MAXN];//y在i时第一个比y小的j
int dp[MAXN][MAXN];
int sx,sy;
inline int cal(int i,int j){
    return sx-i+sy-j;
}
void init(){
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

int main(){
    cin>>x>>y;
    sx = x.size();
    sy = y.size();
    init();  
    int m,a,b;
    cin>>m;
    while(m--){
        cin>>a>>b;
        cout<<dp[a][b]<<endl;
    }
}