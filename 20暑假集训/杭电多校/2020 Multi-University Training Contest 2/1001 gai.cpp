#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
typedef pair<int,int> Pii;
const int MAXN = 1e5+5;
int par[MAXN];
int rk[MAXN];//树高
bool vis[MAXN];
Pii nod[MAXN];
vector<int> e[MAXN];
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
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		vis[i]=rk[i] = 0;
		par[i] = i;
		e[i].clear();
		scanf("%d",&nod[i].first);
		nod[i].second = i;
	}
	sort(nod+1,nod+1+n,greater<Pii>());
	int u,v;
	rep(i,1,m){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ll tot = 0;
	rep(i,1,n){
		vis[nod[i].second] = 1;
		set<int> ltk;
		for(auto v:e[i]){
			if(vis[v]){
				ltk.insert(find(v));
			}
		}
		tot -= (ltk.size()-1)*nod[i].first;
		for(auto x:ltk){
			merge(x,i);
		}
	}
	printf("%lld\n",tot);
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}
