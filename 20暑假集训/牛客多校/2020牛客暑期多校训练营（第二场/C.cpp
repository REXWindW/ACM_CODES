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

int n;
vector<int> e[MAXN];//邻接表 
vector<int> vec;
int d[MAXN] = {0};//记录度 

void dfs(int prev,int x){
	if(d[x]==1) vec.push_back(x);//dfs序存叶子节点 
	for(auto v:e[x]){
		if(v!=prev) dfs(x,v);
	}
}

void solve(){
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++;
		d[v]++; 
	}
	if(n<3){
		cout<<n-1<<endl;
		if(n==2) cout<<"1 2"<<endl;
		return;
	}
	int rt;
	int cnt_leaf=0;//叶子数
	for(int i=1;i<=n;i++){
		if(d[i]>1) rt = i;//找一个度>1的根节点
		else cnt_leaf++;//数叶子数量 
	}
	if(cnt_leaf%2){//如果n为单数，做一个假的叶子节点接在rt上 
		e[rt].push_back(n+1);
		e[n+1].push_back(rt);
		d[n+1]=1;
	}
	dfs(0,rt);
	int siz = vec.size();
	cout<<siz/2<<endl;
	for(int i=0;i<siz/2;i++){
		u = vec[i];
		v = vec[i+siz/2]; 
		if(u==n+1) u=rt;//去掉假的叶子节点 
		else if(v==n+1) v=rt;
		cout<<u<<' '<<v<<endl;
	}
} 

int main(){
	solve();
}
