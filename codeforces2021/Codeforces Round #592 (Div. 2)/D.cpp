#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define int ll
const int MAXN = 114514;
int c[MAXN][3];
int cor[MAXN];
int dp[3][3];//只用管最前面两个
int n;
vector<int> e[MAXN];
vector<int> line;
int st;
int res[MAXN];
void dfs(int now ,int prev){
    line.push_back(now);
    for(auto v:e[now]){
        if(v==prev) continue;
        dfs(v,now);
    }
}
void solve(){
    cin>>n;
    rep(j,0,2){
        rep(i,1,n){
            cin>>c[i][j];
        }
    }
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    rep(i,1,n){
        if(e[i].size()>2){
            cout<<-1<<endl;
            return;
        }
        if(e[i].size()==1) st = i;
    }
    dfs(st,-1);
    int maxi=0,maxj=1;
    rep(i,0,2){
        rep(j,0,2){
            dp[i][j]=0;
            if(i==j) continue;
            dp[i][j]=c[line[0]][i]+c[line[1]][j];
            cor[0]=i;cor[1]=j;
            rep(k,2,n-1){
                cor[k]=3-cor[k-1]-cor[k-2];
                dp[i][j]+=c[line[k]][cor[k]];
            }
            if(dp[i][j]<dp[maxi][maxj]) maxi=i,maxj=j;
        }
    }
    res[line[0]]=maxi;
    res[line[1]]=maxj;
    cor[0]=maxi,cor[1]=maxj;
    rep(i,2,n-1){
        cor[i]=3-cor[i-1]-cor[i-2];
    }
    rep(i,0,n-1){
        res[line[i]]=cor[i];
    }
    cout<<dp[maxi][maxj]<<endl;
    rep(i,1,n){
        cout<<res[i]+1<<' ';
    }
    cout<<endl;
}

signed main(){
    solve();
}