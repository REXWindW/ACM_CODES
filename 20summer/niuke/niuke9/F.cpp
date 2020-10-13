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
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
const int MAXN = 2e6+5;
vector<pll> e[MAXN];
ll dhp[MAXN];//记录该点子树HP变化量
ll drt[MAXN];//记录从该点起始需要多少HP(可能通过休息，可能之前就有 

void dfs(int now,int prev){
	dhp[now] = a[now];//先把这里的苹果吃了 
	for(auto x:e[now]){
		if(x.first==prev) continue;
		dfs(x.first,now);
		dhp[now] += dhp[x.first]; 
		dhp[now] -= 2*x.second;//来回两次 
	}
	[这里需要一个较优的策略依次走该点子树去尽量减少drt[now]]
	drt[now] = 
}

void solve(){
	cin>>n;
	rep(i,1,n){
		dhp[MAXN]=drt[MAXN]=0;
		e[i].clear;
		cin>>a[i];
	}
	int u,v,w;
	rep(i,1,n-1){
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	dfs(1,-1);
}

int main(){
	int z;
	cin>>z;
	while(z--) sovle();
} 
