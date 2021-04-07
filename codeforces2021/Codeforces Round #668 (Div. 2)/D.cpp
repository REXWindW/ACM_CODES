#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 114514;
int n,a,b,da,db;
vector<int> e[MAXN];//邻接表 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

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

void solve(){
	int u,v;
	int dx[MAXN];//直径端点x到各点的距离 
	int dy[MAXN];//直径端点y到各点的距离，同时给找x的时候暂用
    int dal[MAXN]; 
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);//读入节点数量,因为是树，所以边数是n-1 
    rep(i,1,n) e[i].clear();
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);//无向图 
	}
    if(da*2>=db){
        printf("Alice\n");
        return;
    }
	dy[1]=0;
	int x = dfs(-1,1,dy);//注意这里的dy只是用来暂用来找x 
	dx[x]=0;
	int y = dfs(-1,x,dx);//找y
    dal[a] = 0;
    dfs(-1,a,dal);
	int zj = dx[y];
    if(da*2>=min(zj,db)||dal[b]<=da) printf("Alice\n");
    else printf("Bob\n");
}
int main(){
    int z;
    scanf("%d",&z);
    while(z--) solve();
}
