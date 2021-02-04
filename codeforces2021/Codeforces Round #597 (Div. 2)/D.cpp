#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plp;
#define ft first
#define sd second
#define mkp make_pair
const int MAXN = 2020;
const ll LINF = 1ll<<61;
pll a[MAXN];
ll c[MAXN],k[MAXN];
int n;
ll res;
ll d[MAXN][MAXN];
ll diss[MAXN],frm[MAXN];
bool vis[MAXN];
bool flag[MAXN][MAXN];//标记是否再生成树中
bool elev[MAXN];//是否建电站
vector<plp> edges;
vector<int> e[MAXN];
inline ll dis(pll a,pll b){
    return llabs(a.ft-b.ft)+llabs(a.sd-b.sd);
}
inline void prim(){
    int u=1;
    vis[1] = 1;
    while(1){
        rep(v,1,n){
            if(!vis[v]&&diss[v]>d[u][v]){
                diss[v]=d[u][v];
                frm[v]=u;
            }
        }
        int minn=-1;
        rep(i,1,n){
            if(vis[i]) continue;
            if(minn==-1||diss[i]<diss[minn]) minn=i;
        }
        if(minn==-1) break;
        vis[minn]=1;
        res+=d[frm[minn]][minn];
        edges.push_back(mkp(diss[minn],mkp(frm[minn],minn)));
        e[frm[minn]].push_back(minn);
        e[minn].push_back(frm[minn]);
        flag[frm[minn]][minn]=flag[minn][frm[minn]]=1;
        u=minn;
    }
}
int dfs(int now,int prev){//返回最小点下标
    int tmp,ret=now;
    for(auto v:e[now]){
        if(flag[now][v]&&v!=prev){
            tmp = dfs(v,now);
            if(c[tmp]<c[ret])ret=tmp;//找到最便宜的点
        }
    }
    return ret;
}
inline void OK(int u,int v){
    ll min1 = dfs(u,v);
    ll min2 = dfs(v,u);
    if(max(c[min1],c[min2])<d[u][v]){//拆边更划算的情
        flag[u][v]=flag[v][u]=0;//删边
        res-=d[u][v];
        res+=max(c[min1],c[min2]);//多建立一个电站
        elev[min1]=elev[min2]=1;//标记建立电站
    }
}
void solve(){
    res = 0;
    cin>>n;
    rep(i,1,n) cin>>a[i].ft>>a[i].sd;
    rep(i,1,n) cin>>c[i];
    rep(i,1,n) cin>>k[i];
    rep(i,1,n){
        diss[i] = LINF;frm[i]=-1;
        rep(j,i,n){
            d[i][j]=d[j][i]=(k[i]+k[j])*dis(a[i],a[j]);
        }
    }
    prim();//跑prim先高一棵生成树
    int minn=1;//最便宜编号
    rep(i,1,n) if(c[i]<c[minn]) minn=i;
    res+=c[minn];//建立电站
    elev[minn] = 1;
    sort(edges.begin(),edges.end(),greater<plp>());
    int siz = edges.size();
    int u,v;
    rep(i,0,siz-1){
        u = (edges[i].sd).ft;
        v = (edges[i].sd).sd;
        OK(u,v);
    }
    cout<<res<<endl;
    int cnt = 0;
    //电站
    rep(i,1,n) if(elev[i]) cnt++;
    cout<<cnt<<endl;
    rep(i,1,n) if(elev[i]) cout<<i<<' ';
    cout<<endl;
    //电线
    cnt = 0;
    rep(i,0,siz-1){
        u = edges[i].sd.ft;
        v = edges[i].sd.sd;
        if(flag[u][v]) cnt++;
    }
    cout<<cnt<<endl;
    rep(i,0,siz-1){
        u=edges[i].sd.ft;
        v=edges[i].sd.sd;
        if(flag[u][v]) cout<<u<<' '<<v<<endl;
    }
}
int main(){
    solve();   
}