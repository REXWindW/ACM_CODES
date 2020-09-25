#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 2e6+5;

int n;
vector<int> e[MAXN];//存图 
int dfn[MAXN],low[MAXN];
int dfncnt;//dfn自增下标 
int s[MAXN],tp;//数组模拟栈,tp记录大小 
bool in[MAXN];//记录该点是否在栈中 
int scc[MAXN],sc;//节点i所在scc的编号,sc记录有几个强连通 
int sz[MAXN];//强连通i的大小 
int indg[MAXN];//记录缩点后的入度（这题才有的 

void tarjan(int u){
	low[u]=dfn[u]=++dfncnt;//low初始值为自身dfn
	s[++tp]=u;//推u入栈，从1开始 
	in[u]=1;//记录u点在栈中 
	for(auto v:e[u]){//访问到新点的情况 
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);//用low[v}更新low[u] 
		}
		else if(in[v])//v被访问过，但是在栈中 
			low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){//u是连通分量的根节点
		sc++;//强连通数量++
		sz[sc] = 0; 
		while(s[tp]!=u){//u和u之后的点全部出栈 
			scc[s[tp]] = sc;//这个点包含于第几个强连通
			sz[sc]++;//u为根的这个强连通的大小 
			in[s[tp]] = 0;//出栈 
			tp--; 
		}
		scc[u] = sc;//给根节点标，属于第sc个强连通 
		sz[sc]++;
		in[u] = 0;
		tp--;
	}
} 

void reset(){
	tp = sc = dfncnt =0;
	rep(i,1,n){
		in[i] = dfn[i] = 0;//low不用清空，sz在之后用到再清空 
		e[i].clear();
	}
}

int main(){
	cin>>n;
	reset();
	int v;
	rep(u,1,n){
		while(cin>>v&&v!=0) e[u].push_back(v);
	} 
	rep(u,1,n)
		if(!dfn[u]) tarjan(u);
	rep(i,1,sc) indg[i] = 0;//这个不包含在tarjan里面，是这题记录入度的 
	rep(u,1,n){
		for(auto v:e[u]){
			if(scc[u]!=scc[v]) indg[scc[v]]++;
		}
	}
	int res = 0;
	rep(i,1,sc){
		if(indg[i]==0) res++;
	}
	cout<<res<<endl;
}
//洛谷P2835 刻录光盘 https://www.luogu.com.cn/problem/P2835#submit