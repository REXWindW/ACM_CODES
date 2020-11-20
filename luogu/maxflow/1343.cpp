#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
const ll INF = 1ll<<50;
const int MAXN = 2020;
struct Edge{
    int from,to;
    ll cap,flow;
};
vector<int> G[MAXN];
vector<Edge> edges;
int d[MAXN];//dist
int cur[MAXN];
void add_edge(int from,int to,ll cap){
    edges.push_back((Edge){from,to,cap,0});
    edges.push_back((Edge){to,from,0,0});
    int siz = edges.size();
    G[from].push_back(siz-2);
    G[to].push_back(siz-1);
}
int n,m,tot;//n个点m条边x个人
int s,t;
bool bfs(){
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        rep(i,0,(int)G[x].size()-1){
            Edge &e = edges[G[x][i]];
            if(d[e.to]==-1&&e.cap>e.flow){
                d[e.to]=d[x]+1;
                q.push(e.to);
            }
        }
    }
    return d[t]!=-1;
}
ll dfs(int x,ll a){
    if(x==t||a==0) return a;
    ll flow = 0,f;
    for(int &i=cur[x];i<(int)G[x].size();i++){
        Edge &e = edges[G[x][i]];
        if(d[x]+1==d[e.to]&&( (f=dfs(e.to,min(a,e.cap-e.flow)))>0 ) ){
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}
ll Maxflow(){
    ll flow = 0;
    while(bfs()){
        memset(cur,0,sizeof(cur));
        ll now = dfs(s,INF);
        flow+=now;
    }
    return flow;
}
void solve(){
    cin>>n>>m>>tot;
    s = 1,t = n;
    int u,v;
    ll capp;
    rep(i,1,m){
        cin>>u>>v>>capp;
        add_edge(u,v,capp);
    }
    ll mf = Maxflow();
    if(mf==0) cout<<"Orz Ni Jinan Saint Cow!"<<endl;
    else cout<<mf<<' '<<(tot+mf-1)/mf<<endl;
}
int main(){
    solve();
}