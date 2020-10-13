#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 10000

int uN,vN;//u,v的数目
bool g[MAXN][MAXN];//邻接矩阵,一般情况下uv最大范围相同 
int linker[MAXN];//存右节点的对象 
bool used[MAXN]; //右点是否访问过

bool dfs(int u){
	for(int v=0;v<vN;v++){
		if(g[u][v]&&!used[v]){//判断是否有边，是否被用过
			used[v]=true;//标记访问
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;//很精妙，记录新配对，在进行dfs后，连接左右节点的边其实方向反了一反 
				return true; 
			} 
		}
	}
	return false; 
} 

int hungary(){//匈牙利算法 
	int res=0;
	memset(linker,-1,sizeof(linker));//初始化,因为节点uv从0开始，所以linker初始化为-1 
	for(int u=0;u<uN;u++){
		memset(used,false,sizeof(used));
		if(dfs(u)) res++; 
	} 
	return res;
}

int main(){
	int e;
	cin>>uN>>vN>>e;
	int u,v;
	memset(g,0,sizeof(g));
	while(e--){
		scanf("%d%d",&u,&v);
		g[u][v]=1;
	}
	cout<<hungary()<<endl;
}
 
/*匈牙利算法可以解决的问题：
1.二分图的最大匹配数(如婚配问题)
2.最小顶点覆盖------用最少的点覆盖所有的边(如HDOJ禁止早恋,任务安排)
	结论：最小顶点覆盖数==最大匹配数量 
3. DAG(有向无环图)的最小路径覆盖
	(如HDOJ空袭，所有路单行，并且所有街是两个路口相连，已知不会形成回路。问最少空降几个伞兵可以访问所有路口)
	拆点法：1拆成1和1',数字x放左节点，x'放右节点
	DAG图的最小路径覆盖数 == 节点数(n) - 最大匹配数 
*/ 