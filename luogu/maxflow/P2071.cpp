#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 1e5+5;
#define INF 0x7fffffff
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long

struct Edge{
	int from,to;
	ll cap,flow;
};

int n,m,s,t;//节点数，边数(含反向弧)，源点与汇点编号 
vector<Edge> edges;//边长，edges[e]和edges[e^1]互为反向弧 
vector<int> G[MAXN];//邻接表，G[i][j]表示节点i的第j条边在edges中的编号
int d[MAXN];//dist层数，即d[i]为起点到i的距离（层数）,同时也起到vis的作用防止重复走
int cur[MAXN];//这个cur是dfs的时候用来省略重复步骤的

void add_edge(int from,int to,ll cap){
	edges.push_back((Edge){from,to,cap,0});
	edges.push_back((Edge){to,from,0,0});
	int siz = edges.size();
	G[from].push_back(siz-2);//正向边
	G[to].push_back(siz-1);//反向边
}

bool bfs(){
    memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s]=0;//dist(s) = 0
	while(!q.empty()){
		int x=q.front();
		q.pop();
		rep(i,0,G[x].size()-1){
			Edge &e = edges[G[x][i]];
			if(d[e.to]==-1&&e.cap>e.flow){//只考虑残量网络中的弧即这个边还没被填满
				d[e.to]=d[x]+1;//标记层次dist(x)
				q.push(e.to);
			}
		}
	}
	return d[t]!=-1;//找到到t节点的路径则回1，找不到则回0
} 

ll dfs(int x,ll a){//DFS除了当前节点x外，还要传入"目前为止所有边的最小残量"即"水流到这里还剩多少"
	if(x==t||a==0) return a;//也是很简洁一句话 ，结束增广 
 	ll flow = 0,f;
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

ll Maxflow(){
	ll flow=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));//因为有新的反向边引入，即"正向边"更新了 ,有些实际上是反,但dfs里面当正的用 
		flow+=dfs(s,INF);//对当前阻塞流dfs； 
	}
	return flow;
}
void solve(){
    int s1,s2;
    cin>>n;
    s = 0,t = 3*n+1;
    rep(i,1,n){
        add_edge(2*n+i,t,2);
    }
    rep(i,1,2*n){
        add_edge(s,i,1);
        cin>>s1>>s2;
        add_edge(i,2*n+s1,1);
        add_edge(i,2*n+s2,1);
    }
    cout<<Maxflow()<<endl;
}
int main(){
    solve();
}