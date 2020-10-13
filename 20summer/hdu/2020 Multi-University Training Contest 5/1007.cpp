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
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 2e5+5;
typedef pair<int,int> pii;
vector<pii> e[MAXN];
int d[MAXN];
vector<ll> mem[MAXN];
int s;
int n,k;
vector<int> mark;//记录度比k大的的

ll dfs(int now,int prev){
	ll res = 0;
	if(d[now]>k&&now!=s){//要删边的情况
		int siz = e[now].size();
		rep(i,0,siz-1){
			pii& x = e[now][i];
			if(x.first==prev) continue;
			if(!mem[now][i]) mem[now][i] = x.second + dfs(x.first,now);
		}
		vector<ll> px;//用来选出最大k条!到祖先的边必选
		rep(i,0,siz){
			if(e[now][i].first!=prev) px.push_back(mem[now][i]);
		}
		sort(px.begin(),px.end(),greater<int>());
		rep(i,0,k-2){
			res += px[i];
		}
		return res;
	}
	//小于k或者为起点s的情况 
	int siz = e[now].size();
	rep(i,0,siz-1){
		pii& x = e[now][i];
		if(x.first==prev) continue;
		if(!mem[now][i]) mem[now][i] = x.second + dfs(x.first,now);
		res += mem[now][i];
	}
	return res;
}

void solve(){
	read(n);read(k);
	int u,v,w;
	rep(i,1,n){
		d[i] = 0;
		e[i].clear();
		mem[i].clear();
	}
	rep(i,1,n-1){
		read(u);read(v);read(w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
		d[u]++;d[v]++;
	}
	rep(i,1,n){
		if(d[i]>k) mark.push_back(i);
		rep(j,0,d[i]-1) mem[i].push_back(0);//记忆化的数组  
	}
	ll maxx = 0;
	int siz = mark.size();
	rep(i,0,siz-1){
		s = mark[i];
		maxx = max(maxx,dfs(s,-1));
	}
	printf("%lld",maxx);
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}
