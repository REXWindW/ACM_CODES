//spfa O(VE)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=2147483647;
#define m(a) memset(a,0,sizeof(a))
const int N=10005;
int vis[N],dis[N],sum[N];
int n,m,s;
struct node{
    int w,to,next;
}edge[N];
int cnt=1,head[N];
inline void add(int u,int v,int w){
    sum[cnt]=w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void spfa(int x){
    queue<int>q;
    for(int i=1;i<=n;i++){
        dis[i]=INF;vis[i]=0;
    }
    q.push(x);dis[x]=0;vis[x]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();vis[u]=0;
        for(int i=head[u]; i; i=edge[i].next){
            int v=edge[i].to; 
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}