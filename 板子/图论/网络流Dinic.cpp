#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAXN 210
#define INF 0x7fffffff

struct Edge{
	int from,to,cap,flow;
};

int n,m,s,t;//节点数，边数(含反向弧)，源点与汇点编号 
vector<Edge> edges;//边长，edges[e]和edges[e^1]互为反向弧 
vector<int> G[MAXN];//邻接表，G[i][j]表示节点i的第j条边在edges中的编号
bool vis[MAXN];//BFS分层时用;
int d[MAXN];//dist层数，即d[i]为起点到i的距离（层数）
int cur[MAXN];//这个cur是dfs的时候用来省略重复步骤的 

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
int main(){
	int u,v,cap;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&cap);
		add_edge(u,v,cap);
	}
	cout<<Maxflow(1,n)<<endl;
}