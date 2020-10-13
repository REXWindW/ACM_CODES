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

int n,m,s,t;//�ڵ���������(������)��Դ�������� 
vector<Edge> edges;//�߳���edges[e]��edges[e^1]��Ϊ���� 
vector<int> G[MAXN];//�ڽӱ�G[i][j]��ʾ�ڵ�i�ĵ�j������edges�еı��
bool vis[MAXN];//BFS�ֲ�ʱ��;
int d[MAXN];//dist��������d[i]Ϊ��㵽i�ľ��루������
int cur[MAXN];//���cur��dfs��ʱ������ʡ���ظ������ 
int a[MAXN],b[MAXN];

void add_edge(int from,int to,int cap){
	edges.push_back((Edge){from,to,cap,0});
	edges.push_back((Edge){to,from,0,0});
	int m = edges.size();
	G[from].push_back(m-2);//����� 
	G[to].push_back(m-1);//����� 
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
			if(!vis[e.to]&&e.cap>e.flow){//ֻ���ǲ��������еĻ�������߻�û������
				vis[e.to]=1;
				d[e.to]=d[x]+1;//��ǲ��dist(x)
				Q.push(e.to); 
			}
		}
	}
	return vis[t];//�ҵ�����β�ڵ��·�����1���Ҳ���Ŷ���0�����ͦ��̵� 
} 

int dfs(int x,int a){//DFS���˵�ǰ�ڵ�x�⣬��Ҫ����"ĿǰΪֹ���бߵ���С����"��"ˮ�������ﻹʣ����"
	if(x==t||a==0) return a;//Ҳ�Ǻܼ��һ�仰 ���������� 
 	int flow = 0,f; 
	for(int &i=cur[x];i<G[x].size();i++){//��һ���������Ѿ���cur[x]֮ǰ�Ļ����ų��� 
		Edge &e = edges[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			edges[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0) break;//��估ʱ�˳���Ӱ��Ч�� 
		} 
	}
	return flow; 
}

int Maxflow(int ss,int tt){
	s=ss;
	t=tt;
	int flow=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));//��Ϊ���µķ�������룬��"�����"������ ,��Щʵ�����Ƿ�,��dfs���浱������ 
		flow+=dfs(s,INF);//�Ե�ǰ������dfs�� 
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
	s = n*3+1;//����Դ�� 
	t = n*3+2;//������� 
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
