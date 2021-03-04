#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514*8;
int edges[MAXN];
bool ok[MAXN];//边是否存在
vector<int> e[MAXN];
int siz[MAXN];
int fb[35];
int fa[MAXN],fbh[MAXN];//记录每个节点的father,和在edges里的编号
int n;
void init(){
    fb[0]=fb[1] = 1;
    rep(i,2,33) fb[i] = fb[i-1]+fb[i-2];
}
int getfb(int x){//取得fb数组中的下标
    int px = lower_bound(fb+1,fb+1+33,x)-fb;
    if(fb[px]==x) return px;
    return 0;//不是fb数
}
vector<int> points;//记录包含在集合里的点
int to;
void dfs(int now,int prev){
    points.push_back(now);
    siz[now] = 1;
    for(auto v:e[now]){
        if(ok[v]==0) continue;
        if(edges[v]==prev) continue;
        fa[edges[v]]=now;
        fbh[edges[v]] = v;
        dfs(edges[v],now);
        siz[now]+=siz[edges[v]];//处理size
    }
}
bool deal(int now,int dian){
    points.clear();
    dfs(now,-1);//dfs处理size
    int tot = points.size();//总点数
    if(tot<=3) return 1;//切到最小单位了
    int ifb = getfb(tot);
    if(!ifb)//不可能的情况,写下来保险一点
        return 0;
    //cout<<"fbp"<<fb[ifb-1]<<':'<<fb[ifb-2]<<endl;
    for(auto x:points){
        //cout<<"siz"<<x<<'='<<siz[x]<<endl;
        if(siz[x]==fb[ifb-1]||siz[x]==fb[ifb-2]){//可以切割的情况,把它从fa上切下来
            ok[fbh[x]]=ok[fbh[x]^1]=0;//删边
            int faa = fa[x];
            return deal(x,siz[x])&&deal(faa,dian-siz[x]);
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    int u,v;
    rep(i,0,n-2){
        cin>>u>>v;
        edges[2*i]=v;
        edges[2*i+1]=u;
        ok[2*i]=ok[2*i+1]=1;
        e[u].push_back(2*i);
        e[v].push_back(2*i+1);
    }
    if(deal(1,n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    init();
    solve();
}