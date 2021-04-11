#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 50010

int n;
vector<int> e[MAXN];//邻接表 

//这个dfs直接通过船指针来传入d，是为了分别储存dx和dy； 
int dfs(int prev,int u,int *d){//prev是存储上个点的，防止走回头路，这样还直接省掉了vis数组 
	int res = u;//res存储 距离当前点距离最远的点 的编号 
	int siz = e[u].size();
	for(int i=0;i<siz;i++){
		int v = e[u][i];
		if(v!=prev){
			d[v] = d[u]+1;//标记距离 
			int now = dfs(u,v,d);
			if(d[now]>d[res]) res = now;//找到距离当前点最远的点 
		}
	}
	return res;
} 

int main(){
	int u,v;
	int dx[MAXN];//直径端点x到各点的距离 
	int dy[MAXN];//直径端点y到各点的距离，同时给找x的时候暂用 
	scanf("%d",&n);//读入节点数量,因为是树，所以边数是n-1 
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);//无向图 
	}
//	memset(d1,0,sizeof(d1));
//	memset(d2,0,sizeof(d2)); 
	dy[1]=0;
	int x = dfs(-1,1,dy);//注意这里的dy只是用来暂用来找x 
	dx[x]=0;
	int y = dfs(-1,x,dx);//找y
	dy[y]=0;
	dfs(-1,y,dy);//这里才是弄好真正的dy 
	cout<<dx[y]<<endl;
}
