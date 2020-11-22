#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define m(a) memset(a,0,sizeof(a))
const int MAXN=10000;
const int MAXM=100000;
struct Edge{
    int to,next,cap,flow,cost;
}edge[MAXM];
int head[MAXM],tol,pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;
void init(int n){
    N=n;
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
    edge[tol].to=v;         edge[tol].cap=cap;
    edge[tol].cost=cost;    edge[tol].flow=0;
    edge[tol].next=head[u]; head[u]=tol++;
    edge[tol].to=u;         edge[tol].cap=0;
    edge[tol].cost=-cost;   edge[tol].flow=0;
    edge[tol].next=head[v]; head[v]=tol++;
}
bool spfa(int s,int t){
    queue<int>q;
    for(int i=0;i<N;i++){
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    dis[s]=0;vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)return false;
    else return true;
}
int cost;
int minCostMaxflow(int s,int t){
    int flow=0;
    cost=0;
    while(spfa(s,t)){
        int Min=INF;
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow){
                Min=edge[i].cap-edge[i].flow;
            }
        }
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=Min;
            edge[i^1].flow-=Min;
            cost+=edge[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}
int n,k,s,t;
int main(){
    int Case;cin>>Case;
    while(Case--){
        cin>>n>>k;
        init(2*n+2);
        for(int i=1;i<=n*(n-1)/2;i++){
            int u,v,w;
            cin>>u>>v>>w;
            addedge(u,v+n,1,w);
        }
        s=1,t=n+n;
        cout<<minCostMaxflow(s,t)<<' '<<cost<<endl;
    }
}