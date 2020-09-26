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

const int MAXN = 1e5+5;
int siz[MAXN];
int bigg[MAXN];//记录重儿子的大小 
int n;
vector<int> e[MAXN];
int res,resprev;
void dfs(int pos ,int prev){
	siz[pos] = 1;
	bigg[pos] = 0;
	for(auto v:e[pos]){
		if(v==prev) continue;
		dfs(v,pos);
		bigg[pos] = max(bigg[pos],siz[v]);
		siz[pos] += siz[v];	
	}
	bigg[pos] = max(bigg[pos],n-siz[pos]);
}

void dfs2(int pos,int prev){
	//cout<<pos<<endl;
	if(e[pos].size()==1){
		res = pos;
		resprev = prev;
		return;
	}
	for(auto v:e[pos]){
		if(v==prev) continue;
		dfs2(v,pos);
		if(res) return;
	}
}

void solve(){
	cin>>n;
	int u,v;
	rep(i,1,n){
		e[i].clear();
	}
	rep(i,1,n-1){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,-1);
	int minn = INF;
	rep(i,1,n) minn = min(bigg[i],minn); 
	vector<int> zx;
	rep(i,1,n) if(bigg[i]==minn) zx.push_back(i);
	if(zx.size()==1){
		cout<<1<<' '<<e[1][0]<<endl;
		cout<<1<<' '<<e[1][0]<<endl;
		return;
	}
	else{
		res = 0;
		dfs2(zx[0],zx[1]);
		cout<<res<<' '<<resprev<<endl;
		cout<<res<<' '<<zx[1]<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

