#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);

const int MAXN = 1e6+5;
const int LOGN = log(MAXN)/log(2)+5; 

int z,m,n;
int fa[MAXN],p[MAXN][LOGN];
int L[MAXN];//记录深度 
int lg[MAXN];
vector<int> e[MAXN];

void init_lg(){//预处理lg，给之后计算省时间 
	lg[1]=0;
	for(int i=2;i<MAXN;i++) lg[i]=lg[i-1]+( (1<<(lg[i-1]+1))==i );
} 

void dfs(int x){
	for(auto u:e[x]){
		L[u]=L[x]+1;
		dfs(u);
	}
}

void preprocess(int n){
	for(int i=1;i<=n;i++)
		for(int j=0;1<<j<=n;j++) p[i][j]=-1;//有些倍增后出界的，用-1标记 
	for(int i=1;i<=n;i++)
		p[i][0]=fa[i];//倍增长度为1的时候指向格子的父节点
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i<=n;i++)
			if(p[i][j-1]!=-1) p[i][j]=p[p[i][j-1]][j-1];//两端长度加起来正好是两倍即次数+1 
}

int LCA(int u,int v){
	if(L[u]<L[v]) swap(u,v);//u成为离根节点更远的
	int log = lg[L[u]];//找到L[u]的二进制最高位 
	for(int i=log;i>=0;i--)
		if(L[u]-(1<<i)>=L[v]) u=p[u][i];//u往上爬到与v同高
	if(u==v) return u;
	for(int i=log;i>=0;i--)
		if(p[u][i]!=-1&&p[u][i]!=p[v][i]){//找公共祖先,逼近它但是又不超过它 
			u=p[u][i]; v=p[v][i]; 
		} 
	return fa[u];
} 

int main(){
	init_lg();//预处理log2x，给之后的计算省时间 
	int z,q,u,v;
	string aa,bb;
	cin>>z;
	while(z--){
		map<string,int>mp;
		cin>>n>>q;
		if(n==1){
			while(q--){
				cin>>aa>>bb;cout<<0<<endl;
			}
			continue;
		}
		int countt = 0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<n;i++){
			cin>>aa>>bb;
			int &a = mp[aa];int &b = mp[bb];
			if(!a) a=++countt;
			if(!b) b=++countt;
			fa[a]=b;
			e[b].push_back(a);
		}
		int rt;
		for(int i=1;i<=n;i++){
			if(fa[i]==i) {
				rt=i;break;
			}
		}
		L[rt]=1;
		dfs(rt);
		preprocess(n);
		int res;
		while(q--){
			cin>>aa>>bb;
			int &a = mp[aa];int &b = mp[bb];
			int lc = LCA(a,b);
			res = L[a]-L[lc];
			if(lc!=b) res++;
			cout<<res<<endl;
		}
		for(int i=1;i<=n;i++) e[i].clear();
	}
}