#include<iostream>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 1e5+5;
const int MAXM = 1e5+5;
int sz[MAXN],son[MAXN];//子树大小和重儿子
//int ans[MAXN];//存最多的颜色和编号和,这题没必要
int c[MAXN];//每个点的颜色
int cnt[MAXM];//存每种颜色的点数
ll bhh[MAXN],bsum;//题目要求颜色的编号和
int maxx;//临时变量,用来找最大颜色数量的
int n;
vector<int> e[MAXN];
void init(int now,int pre){//预处理找重儿子
    sz[now] = 1;son[now] = -1;
    for(auto v:e[now]){
        if(v==pre) continue;
        init(v,now);
        sz[now]+=sz[v];
        if(son[now]==-1||sz[v]>sz[son[now]]) son[now]=v;
    }
}
void dfs1(int now,int pre,int val,int rt){//rt是dfs里面当前在统计的子树根
//val=1的时候加上子节点的贡献,而-1时是dfs里面opt=1(代表轻儿子)时删去贡献
    cnt[c[now]]+=val;
    if(val==1){
        if(cnt[c[now]]>maxx) maxx=cnt[c[now]],bsum=c[now];
        else if(cnt[c[now]]==maxx) bsum+=c[now];
    }
    //遍历子节点的时候看到什么颜色就检查这个颜色
    for(auto v:e[now]) if(v!=pre)dfs1(v,now,val,rt);
}
void dfs(int now,int pre,int opt){//opt为1代表要清空
    for(auto v:e[now]){
        if(v!=son[now]&&v!=pre) dfs(v,now,1);//先轻儿子,需要删去
    }
    if(son[now]!=-1) dfs(son[now],now,0);//处理重儿子
    //此时计算轻儿子的贡献,重儿子的在cnt里面祖传上来了
    for(auto v:e[now]){
        if(v!=pre&&v!=son[now]) dfs1(v,now,1,now);//统计轻儿子上的结果
    }
    cnt[c[now]]++;//也要加上当前节点
    if(cnt[c[now]]>maxx) maxx=cnt[c[now]],bsum=c[now];
    //这里我一开始用的cnt[c[now]]>cnt[ans[now]],但是c[now]和ans[rt]相同时出问题
    else if(cnt[c[now]]==maxx) bsum+=c[now];
    bhh[now] = bsum;//记录结果
    //减去轻儿子的贡献
    if(opt){
        cnt[c[now]]--;
        for(auto v:e[now])
            if(v!=pre) dfs1(v,now,-1,now);
        maxx = bsum = 0;//删去轻儿子这颗子树对bsum和maxx的贡献
    }
}
int rt = 1;//题目默认1为根节点
int main(){
    cin>>n;
    rep(i,1,n) cin>>c[i];
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init(rt,-1);
    dfs(rt,-1,1);
    rep(i,1,n){
        cout<<bhh[i];
        if(i!=n) cout<<' ';  
    }
    cout<<endl;
}
//没有修改只有查询的树形问题
//且询问以所有节点为根子树（即对每个节点为根的子树都要询问）。
//洛谷CF600E Lomsat gelral
//https://www.luogu.com.cn/problem/CF600E