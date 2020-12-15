#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int MAXN = 114514;
int n,m;
vector<int>e[MAXN];
bool vis[MAXN];
bool flag[MAXN];//标记割点
int res;//记录割点数量
int low[MAXN],dfn[MAXN],dfncnt;//老tarjan了

void Tarjan(int u,int pre){//pre=-1时代表是祖先
    vis[u] = 1;
    low[u] = dfn[u] = ++dfncnt;
    int cntchild=0;//儿子数量
    for(auto v:e[u]){
        if(!vis[v]){
            cntchild++;
            Tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(pre!=-1&&low[v]>=dfn[u]&&!flag[u]){//算法核心
                flag[u]=1;
                res++;
            }
        }
        else if(v!=pre)//往上的边,更新当前节点的low
            low[u] = min(low[u],dfn[v]);
    }
    if(pre==-1&&cntchild>=2&&!flag[u]){//u为祖先要另外讨论
        flag[u]=1;
        res++;
    }
}

void solve(){
    cin>>n>>m;
    //初始化
    rep(i,1,n){vis[i]=flag[i]=0;e[i].clear();}
    res=dfncnt=0;
    int u,v;
    rep(i,1,m){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    rep(i,1,n) if(!vis[i]) Tarjan(i,-1);//也可在这重置dfncnt
    cout<<res<<endl;
    rep(i,1,n){
        if(flag[i]) cout<<i<<' ';
    }
    cout<<endl;
}
int main(){
    solve();
}
//P3388 【模板】割点（割顶）
//https://www.luogu.com.cn/problem/P3388