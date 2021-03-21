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
#define int ll
ll mem[305][305][1005];//第几行/多少长/占多少容量
int a[305][305];
ll sum[305][305];
int n,m,k;
void dfs(int now,int prel,int rk){//当前行,上一行长度,剩下k
    if(now==n+1){
        return;
    }
    if(rk==0) return;
    if(mem[now][prel][rk]) return;//记忆化搜索
    int top = min(prel,rk);
    int bot = (rk+(n-now))/(n-now+1);//剪枝1,排除选了后面放不满的情况
    rep(nl,bot,top){
        dfs(now+1,nl,rk-nl);//表示不可行
        mem[now][prel][rk]
        =max(mem[now][prel][rk],sum[now][nl]+mem[now+1][nl][rk-nl]);
    }
}
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n){//前缀和
        sum[i][0]=0;
        rep(j,1,m){
            cin>>a[i][j];
            sum[i][j] = sum[i][j-1]+a[i][j];
        }
    }
    dfs(1,m,k);
    cout<<mem[1][m][k]<<endl;
}

signed main(){
    solve();
}