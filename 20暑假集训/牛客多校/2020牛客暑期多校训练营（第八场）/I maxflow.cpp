#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e5+5;

struct Edge{
	int from,to,cap,flow;
};

int n,m,s,t;//节点数，边数(含反向弧)，源点与汇点编号 
vector<Edge> edges;//边长，edges[e]和edges[e^1]互为反向弧 
vector<int> G[MAXN];//邻接表，G[i][j]表示节点i的第j条边在edges中的编号
bool vis[MAXN];//BFS分层时用;
int d[MAXN];//dist层数，即d[i]为起点到i的距离（层数）
int cur[MAXN];//这个cur是dfs的时候用来省略重复步骤的 
int a[MAXN],b[MAXN];

void add_edge(int from,int to,int cap){
	edges.push_back((Edge){from,to,cap,0});
	edges.push_back((Edge){to,from,0,0});
	int m = edges.size();
	G[from].push_back(m-2);//正向边 
	G[to].push_back(m-1);//反向边 
}

bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(s);
	d[s]=0;//dist(s) = 0
	vis[s]=1;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=0;i<G[x].size();i++){
			Edge &e = edges[G[x][i]];
			if(!vis[e.to]&&e.cap>e.flow){//只考虑残量网络中的弧即这个边还没被填满
				vis[e.to]=1;
				d[e.to]=d[x]+1;//标记层次dist(x)
				Q.push(e.to); 
			}
		}
	}
	return vis[t];//找到到结尾节点的路径则回1，找不断哦则回0，这句挺简短的 
} 

int dfs(int x,int a){//DFS除了当前节点x外，还要传入"目前为止所有边的最小残量"即"水流到这里还剩多少"
	if(x==t||a==0) return a;//也是很简洁一句话 ，结束增广 
 	int flow = 0,f; 
	for(int &i=cur[x];i<G[x].size();i++){//上一次阻塞流已经把cur[x]之前的弧都排除了 
		Edge &e = edges[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			edges[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0) break;//这句及时退出很影响效率 
		} 
	}
	return flow; 
}

int Maxflow(int ss,int tt){
	s=ss;
	t=tt;
	int flow=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));//因为有新的反向边引入，即"正向边"更新了 ,有些实际上是反,但dfs里面当正的用 
		flow+=dfs(s,INF);//对当前阻塞流dfs； 
	}
	return flow;
} 

void solve(int tnum){
	map<int,bool> viss;
	scanf("%d",&n);
	edges.clear();
	rep(i,1,3*n+2){
		G[i].clear();
	}
	s = n*3+1;//超级源点 
	t = n*3+2;//超级汇点 
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		add_edge(s,2*n+i,1);
		add_edge(2*n+i,a[i],1);
		add_edge(2*n+i,b[i],1);
		if(!viss[a[i]]){
			viss[a[i]]=1;
			add_edge(a[i],n*3+2,1);
		}
		if(!viss[b[i]]){
			viss[b[i]]=1;
			add_edge(b[i],n*3+2,1);
		}
	}
	int res = Maxflow(s,t);
	printf("Case #%d: %d\n",tnum,res);
}

int main(){
	freopen("inputs.txt","r",stdin);
	freopen("outputs.txt","w",stdout);
	int z;
	scanf("%d",&z);
	rep(j,1,z) solve(j); 
}
