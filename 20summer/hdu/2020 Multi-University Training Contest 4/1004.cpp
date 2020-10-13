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

const ll LINF = 1e18;

const int MAXN = 1e5+5;
ll n,m,s,t,hs;
ll hand[MAXN];//1=R，0=M，-1=L 
vector<ll> e[MAXN];
vector<ll> w[MAXN];
bool vis[MAXN][2];
ll d[MAXN][2];//分左手右手去处理 

void solve(){
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&hs);
	char hc;
	getchar();
	rep(i,1,n){
		scanf("%c",&hc);
		if(hc=='L') hand[i] = -1;
		else if(hc=='R') hand[i] = 1;
		else hand[i] = 0;
		//初始化 
		e[i].clear();
		w[i].clear();
		d[i][0] = d[i][1] = LINF;
		vis[i][0] = vis[i][1] = 0;
	}
	int u,v,dis;
	rep(i,1,m){
		scanf("%d%d%d",&u,&v,&dis);
		e[u].push_back(v);
		e[v].push_back(u);
		w[u].push_back(dis);
		w[v].push_back(dis);
	}
	if(hand[s]==1) d[s][1] = 0;//看出发点是左手还是右手 
	else if(hand[s]==-1) d[s][0] = 0;
	else d[s][0]=d[s][1] = 0; 
	rep(i,1,n){
		int x;
		ll m=LINF;
		//左手 
		rep(y,1,n){
			if(!vis[y][0]&&d[y][0]<m) m=d[x=y][0];
		}
		if(m!=LINF){
			vis[x][0] = 1;//左手最短路已经找到
			int siz = e[x].size();
			for(int i=0;i<siz;i++){
				int v = e[x][i];
				if(!vis[v][0]){//左手，这种情况不用换手 
					if(hand[v]==1);
					else{
						d[v][0]=min(d[v][0],d[x][0]+w[x][i]);
					}
				}
				if(!vis[v][1]){//右手，这种情况要换手
					if(hand[v]==0);
					else{
						d[v][1]=min(d[v][0],d[x][0]+w[x][i]+hs);
					}
				}
			}
		}
		//右手 
		m=LINF;
		if(m!=LINF){
			rep(y,1,n){
				if(!vis[y][1]&&d[y][1]<m) m=d[x=y][1];
			}
			vis[x][1] = 1;
			int siz = e[x].size();
			for(int i=0;i<siz;i++){
				int v = e[x][i];
				if(!vis[v][0]){//左手，这种情况要换手 
					if(hand[v]==1);
					else{
						d[v][0]=min(d[v][0],d[x][0]+w[x][i]+hs);
					}
				}
				if(!vis[v][1]){//右手，这种情况要换手
					if(hand[v]==0);
					else{
						d[v][1]=min(d[v][0],d[x][0]+w[x][i]);
					}
				}
			}
		}
	}
	printf("%lld\n",min(d[t][0],d[t][1]));
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

