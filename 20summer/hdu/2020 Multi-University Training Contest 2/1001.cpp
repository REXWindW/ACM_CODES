/*
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
*/ 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<set>
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

struct node{
	int num;
	int data;
	vector<int> e;
	friend bool operator < (node a,node b){
		if(a.data>b.data) return 1;
		else if(a.data==b.data&&a.e.size()>b.e.size()) return 1;
		return 0;
	}
}p[MAXN]; 

int mp[MAXN];
int par[MAXN];
int rk[MAXN];//树高
int m,n;

int find(int x){//路径压缩find 
	if(par[x]==x) return x;
	else return par[x] = find(par[x]);
}

inline void merge(int x,int y){ 
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(rk[x]<rk[y]) par[x] = y;//树高优化并查集 
	else{
		par[y] = x;
		if(rk[x]==rk[y]) rk[x]++;
	}
}

void solve(){
	ll tot = 0;
	read(n),read(m);
	rep(i,1,n){
		p[i].e.clear();
		read(p[i].data);
		p[i].num = i;
		par[i]=i;rk[i]=0;
	}
	int u,v;
	rep(i,1,m){
		read(u),read(v);
		p[u].e.push_back(v);
		p[v].e.push_back(u);
	}
	sort(p+1,p+1+n);
	rep(i,1,n) mp[p[i].num] = i;
	rep(i,1,n){
		set<int> ltk;//用来求连通块数量
		//cout<<"edges";
		for(auto v:p[i].e){
			//cout<<v<<' ';
			int vmp = mp[v];
			if(vmp<i){//<i的点之前已经都加入进来了 
				ltk.insert(find(vmp));
			}
		}
		tot -= (ltk.size()-1)*p[i].data;
		//如果连通块是0，tot是增加的
		for(int x:ltk){//遍历集合，合并
			merge(x,i);
		}
	}
	printf("%lld\n",tot);
}

int main(){
	freopen("1001.in","r",stdin);
	freopen("outputs.txt","w",stdout);
	int z;
	read(z);
	while(z--) solve();
}

