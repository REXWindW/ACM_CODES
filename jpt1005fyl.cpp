#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define m(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN=2020;
const int MAXM=40010;
struct Edge{
    int to,next,cap,flow,cost;
}edge[MAXM<<1];
int head[MAXM],tol,pre[MAXN],dis[MAXN];
int mvis[MAXN][MAXM];
bool vis[MAXN];
int a[MAXN];
int mcost[MAXM];
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
int n,m,k,s,t;
typedef pair<int,int> pii;
#define mkp make_pair
void solve(){
  init(2000);
  s = 0;t = 1999;
  cin>>n>>m;
  rep(i,1,n){
    cin>>a[i];
  }
  int hs,ht;
  priority_queue<pii,vector<pii>,greater<pii>>q;
  rep(i,1,m){
    cin>>hs>>ht>>mcost[i];
    q.push(mkp(hs,i));//进来
    q.push(mkp(ht+1,-i));//出去
  }
  a[0] = 0;
  a[n+1] = 0;
  map<int,int> mpz,mpf;
  rep(i,1,n+1){
    rep(j,1,m){
      mvis[i][j] = mvis[i-1][j];
    }
    while(!q.empty()&&q.top().first==i){
      if(q.top().second<0) mvis[i][abs(q.top().second)]--;
      else mvis[i][abs(q.top().second)]++;
      q.pop();
    }//标记所有m的项
    if(i!=1){
      addedge(i,i-1,INF,0);//b
      //cout<<"edgeb"<<i<<' '<<i-1<<" INF "<<0<<endl;
    }
    if(a[i]-a[i-1]>=0){
      //addedge(s,i,INF,0);//mark
      addedge(s,i,a[i]-a[i-1],0);
      //cout<<"edgea"<<s<<' '<<i<<' '<<a[i]-a[i-1]<<' '<<0<<endl;
    }
    else{
      //addedge(i,t,INF,0);
      addedge(i,t,a[i-1]-a[i],0);
      //cout<<"edgea"<<i<<' '<<t<<' '<<a[i-1]-a[i]<<' '<<0<<endl;
    }
    rep(j,1,m){
      /*
      if(mvis[i][j]==mvis[i-1][j]) cout<<'=';
      else if(mvis[i][j]) cout<<"+";
      else cout<<"-";
      */
      if(mvis[i][j]==mvis[i-1][j]) continue;
      else if(mvis[i][j]){//正
        mpz[j] = i;
      }
      else if(mvis[i-1][j]){//负
        mpf[j] = i;
      }
    }
  }
  rep(j,1,m){
    addedge(mpz[j],mpf[j],INF,mcost[j]);
    //cout<<"edgem"<<mpz[j]<<' '<<mpf[j]<<' '<<"INF"<<mcost[j]<<endl;
  }
  minCostMaxflow(s,t);
  //cout<<"flow:"<<res<<endl;
  cout<<cost<<endl;
}
int main(){
  solve();
}