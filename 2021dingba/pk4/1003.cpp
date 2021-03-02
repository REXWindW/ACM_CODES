#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAXN 114514
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x7fffffff
int n,p;
vector<int> e[MAXN];//邻接表 
vector<int> w[MAXN];

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
int minn[MAXN],min2[MAXN];
int dx[MAXN];//直径端点x到各点的距离 
int dy[MAXN];//直径端点y到各点的距离，同时给找x的时候暂用 
void solve(){
	int u,v,ww;
	scanf("%d%d",&n,&p);//读入节点数量,因为是树，所以边数是n-1 
    rep(i,1,n){
        e[i].clear();
        w[i].clear();
        minn[i]=INF;min2[i]=INF;
    }
    for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&ww);
		e[u].push_back(v);
		e[v].push_back(u);//无向图
        w[u].push_back(ww);
        w[v].push_back(ww);
        //同时维护最小值和次小值;
        if(ww<=minn[u]){
            min2[u]=minn[u];
            minn[u]=ww;
        }
        if(ww<=minn[v]){
            min2[v]=minn[v];
            minn[v]=ww;
        }
	}
    if(p==1){
        if(n!=1) printf("2\n");
        else printf("1\n");
        return;
    }
    if(p==2){
        dy[1]=0;
        int x = dfs(-1,1,dy);//注意这里的dy只是用来暂用来找x 
        dx[x]=0;
        int y = dfs(-1,x,dx);//找y
        dy[y]=0;
        dfs(-1,y,dy);//这里才是弄好真正的dy 
        printf("%d\n",dx[y]+1);
    }
}
int main(){
    int z;
    scanf("%d",&z);
    while(z--) solve();
}