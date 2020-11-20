#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
int n,m,s,t;
struct Edge{
    int from,to,cap,flow;
};
const int MAXN = 233;
int cur[MAXN];
int d[MAXN];
vector<int> G[MAXN];
vector<Edge> edges;
void add_edge(int from,int to){
    edges.push_back( (Edge){from+n,to,INF,0} );
    edges.push_back( (Edge){to+n,from,INF,0} );
    int siz = edges.size();
    G[from+n].push_back(siz-2);
    G[to+n].push_back(siz-1);
}
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
int dfs(int x,int a){
    if(x==t||a==0) return a;
    int flow = 0,f;
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
int Maxflow(){
    int flow = 0;
    while(bfs()){
        memset(cur,0,sizeof(cur));
        int now = dfs(s,INF);
        flow+=now;
    }
    return flow;
}
void solve(){
    cin>>n>>m>>s>>t;
    int u,v;
    rep(i,1,n){
        edges.push_back( (Edge){i,i+n,1,0} );
        edges.push_back( (Edge){i+n,i,0,0} );
        int siz = edges.size();
        G[i].push_back(siz-2);
        G[i+1].push_back(siz-1);
    }
    rep(i,1,m){
        cin>>u>>v;
        add_edge(u,v);
    }
    s+=n;
    cout<<Maxflow()<<endl;
}
int main(){
    solve();
}