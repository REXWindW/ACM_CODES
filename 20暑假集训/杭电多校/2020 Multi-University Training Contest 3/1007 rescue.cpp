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

const int MAXN = 66;
int g[MAXN][MAXN];
int n,k;
int d[MAXN],f[MAXN][MAXN];//这个f必须二维，不然dfs会有影响 
bool vis[MAXN];
int res;

void dfs(int m){
	rep(i,1,n) d[i]=INF,vis[i]=f[m][i]=0;
	d[1] = 0;
	rep(i,1,n){
		int x,ma = INF;
		rep(y,1,n){
			if(!vis[y]&&d[y]<ma) ma=d[x=y];//当前最近的 
		}
		vis[x] = 1;
		rep(y,1,n){
			if(!vis[y]&&d[y]>d[x]+g[x][y]){
				d[y] = d[x] + g[x][y];
				f[m][y] = x;//y前面一个点是x
			}
		}
	}
	if(m==k){
		res = max(res,d[n]);
		return;
	}
	int p = n;
	while(p!=1){//从终点往回找路
		int hc = g[p][f[m][p]];
		g[p][f[m][p]] = g[f[m][p]][p] = INF;
		dfs(m+1);
		g[p][f[m][p]] = g[f[m][p]][p] = hc;
		p = f[m][p];
	}
} 

void solve(){
	cin>>n>>k;
	rep(i,1,n)
		rep(j,1,n) g[i][j] = INF;
	int u,v,w;
	rep(i,1,n*(n-1)/2){
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	res = 0;
	dfs(0);
	cout<<res<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}
 

