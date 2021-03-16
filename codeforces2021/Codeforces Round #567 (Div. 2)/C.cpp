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

const int MAXN = 2021;
int dp[MAXN][MAXN];
int top[MAXN][MAXN];//当前颜色往上到哪里
int n,m;
int a[MAXN][MAXN];
ll tot = 0;
bool he(int i,int j){//检验三个颜色段是否相同
    int ht = top[i][j];
    i-=ht;//新的颜色段
    if(i<=0||top[i][j]!=ht) return 0;
    i-=ht;
    if(i<=0||top[i][j]<ht) return 0;//这个地方不是=!!一开始错这里
    return 1;
}
bool OK(int i,int j){
    if(dp[i][j-1]==0) return 0;//保证前面的可以成棋子
    if(top[i][j-1]!=top[i][j]) return 0;//长度相同
    int ht = top[i][j];
    if(a[i][j]!=a[i][j-1]||a[i-ht][j]!=a[i-ht][j-1]||a[i-ht*2][j]!=a[i-ht*2][j-1]) return 0;
    //保证颜色相同
    return 1;
}
void solve(){
    cin>>n>>m;   
    char hc;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            a[i][j] = hc-'a';
        }
    }
    rep(i,1,n) a[i][0]=-1;
    rep(j,1,m) a[0][j]=-1;
    rep(i,1,n){
        rep(j,1,m){
            if(a[i][j]==a[i-1][j]) top[i][j]=top[i-1][j]+1;
            else top[i][j] = 1;//当前格子往上同颜色长度
        }
    }
    tot = 0;
    rep(i,3,n){//肯定至少要从第三行开始的
        rep(j,1,m){
            if(he(i,j)){
                dp[i][j]=1;//自己可以成棋子
                if(OK(i,j)){
                    dp[i][j]+=dp[i][j-1];//和前面的也能组成棋子
                }
                tot+=dp[i][j];
            }
        }
    }
    cout<<tot<<endl;
}
int main(){
    solve();
}