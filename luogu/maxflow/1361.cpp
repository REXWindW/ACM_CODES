#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
struct Edge{
    int from,to;
    ll cap,flow;
};
#define INF 0x3f3f3f3f
const int MAXN = 3077;
vector<Edge> edges;
vector<int> G[MAXN];
int d[MAXN];
int cur[MAXN];
int n,m,s,t; m
ll summ;
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
    int flow = 0;
    while(bfs()){
        memset(cur,0,sizeof(cur));
        int now = dfs(s,INF);
        flow+=now;
    }
    return flow;
}
void add_edge(int from,int to,ll cap){
    edges.push_back((Edge){from,to,cap,0});
    edges.push_back((Edge){to,from,0,0});
    int siz = edges.size();
    G[from].push_back(siz-2);
    G[to].push_back(siz-1);
}
void solve(){
    summ = 0;
    cin>>n;
    s = 0,t = 3020;//A and B represent source n end
    int tai,tbi;//temp ai n bi
    rep(i,1,n){
        cin>>tai;
        summ += tai;
        add_edge(0,i,tai);
    }
    rep(i,1,n){
        cin>>tbi;
        summ += tbi;
        add_edge(i,2020,tbi);
    }
    cin>>m;//how many groups
    int tki,tca,tcb;//temp
    summ += tca+tcb;
    int hc;
    rep(i,1,m){
        cin>>tki>>tca>>tcb;
        //n+m and 2n+m for two devide points
        add_edge(1,n+m,tca);
        add_edge(2*n+m,3020,tcb);
        rep(i,1,tki){
            cin>>hc;
            add_edge(n+m,hc,INF);
            add_edge(hc,2*n+m,INF);
        }
    }
    cout<<Maxflow()<<endl;
}
int main(){
    solve();
}