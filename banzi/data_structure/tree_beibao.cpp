#include<iostream>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
int cansel_sync =(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 333;
struct Node{
	int v,nxt;//next同一个父亲的下一个点
	int w;//权值,这题用不到
}edges[MAXN];
int head[MAXN];//记录u为起点的第一条边编号
int cnt;//总边数
int minn;
inline void add(int u,int v){//增加边
	edges[++cnt] = Node{v,head[u]};
	head[u]=cnt;
}
int n,m;
int dp[MAXN][MAXN],val[MAXN];
void dfs(int now){
	dp[now][1] = val[now];//肯定要选定自己
	for(int i = head[now];i!=-1;i=edges[i].nxt){
		int v = edges[i].v;
		dfs(v);
		//分组背包
		repb(j,m,1){//当前u背包容量
			rep(k,0,j-1){//从v儿子里拿几个
				dp[now][j]=max(dp[now][j],dp[now][j-k]+dp[v][k]);
				//状态转移
			}
		}
	}
}
int main(){
	while(cin>>n>>m&&m&&n){
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		cnt = 0;
		int fa;//fa表示依赖的点
		rep(i,1,n){
			cin>>fa>>val[i];
			add(fa,i);
		}
		m++;//因为之后的dp[0][m]算上了0点,所以要+1
		val[0]=0;//构造虚节点0
		dfs(0);
		cout<<dp[0][m]<<endl;
	}
}
//洛谷P2014 [CTSC1997]选课
//https://www.luogu.com.cn/problem/P2014