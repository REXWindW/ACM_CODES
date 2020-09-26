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
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 2e5+5;
vector<int> e[MAXN];
int n;
ll dep[MAXN];
ll size[MAXN];
ll qz[MAXN];

struct node{
	int pos;
	ll dqz;
}; 

node nod[MAXN];

bool cmp(node a,node b){
	return a.dqz>b.dqz;
}

inline void show(){
	cout<<"show dep"<<endl;
	for(int i=1;i<=n;i++){
		cout<<dep[i]<<' ';
	}
	cout<<endl;
	cout<<"show size"<<endl;
	for(int i=1;i<=n;i++){
		cout<<size[i]<<' ';
	}
	cout<<endl;
	cout<<"show qz"<<endl;
	for(int i=1;i<=n;i++){
		cout<<qz[i]<<' ';
	}
	cout<<endl;
}

void dfs(int u,int prev){
	size[u] = 1;//初始化size数组 
	dep[u] = dep[prev]+1;//写入dep 
	qz[u] = dep[u];//初始化qz 
	if(e[u].size()==1&&e[u][0]==prev){
		return;
	}
	for(auto v:e[u]){
		if(v==prev) continue;
		dfs(v,u);
		size[u] += size[v];
		qz[u] += qz[v];
	}
}

inline void solve(){
	for(int i=1;i<=n;i++) e[i].clear();
	int vv;
	for(int i=2;i<=n;i++){
		cin>>vv;
		e[vv].push_back(i);
		e[i].push_back(vv);
	}
	dep[0] = 0;
	dfs(1,0);
	show();
	for(int i=1;i<=n;i++){
		nod[i] = node{i,dep[i]*size[i]};
	}
	sort(nod+2,nod+1+n,cmp);//依据权值从大到小对点排序
	ll res = 0;//结果 
	ll now = 0;
	for(int i=1;i<=n;i++){
		now += nod[i].dqz;
		res = res + qz[1] - now;
		cout<<"res"<<i<<'='<<res<<endl;
	}
	cout<<res<<endl;
}

int main(){
	while(cin>>n) solve();
}

