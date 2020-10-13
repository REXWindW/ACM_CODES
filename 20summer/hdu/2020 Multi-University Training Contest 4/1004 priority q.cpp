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
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
typedef pair<ll,ll> pll; 
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const ll LINF = 1e18;

const int MAXN = 1e5+5;
ll n,m,s,t,hs;
ll hand[MAXN];//1=R，0=M，-1=L 
vector<pll> e[MAXN];
bool vis[MAXN][2];
ll d[MAXN][2];//分左手右手去处理 

void solve(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&t,&hs);
	char hc;
	getchar();
	rep(i,1,n){
		scanf("%c",&hc);
		if(hc=='L') hand[i] = -1;
		else if(hc=='R') hand[i] = 1;
		else hand[i] = 0;
		//初始化 
		e[i].clear();
		d[i][0] = d[i][1] = LINF;
		vis[i][0] = vis[i][1] = 0;
	}
	int u,v;
	ll dis;
	rep(i,1,m){
		scanf("%d%d%lld",&u,&v,&dis);
		e[u].push_back(make_pair(dis,v));
		e[v].push_back(make_pair(dis,u));
	}
	priority_queue<pll,vector<pll>,less<pll> >q[2];//两个队列，分别是0左手1右手的 
	if(hand[s]==1) d[s][1]=0;//看出发点是左手还是右手 
	else if(hand[s]==-1) d[s][0] = 0;
	else d[s][0]=d[s][1] = 0;
	if(d[s][1]==0) q[1].push(make_pair(0,s));
	if(d[s][0]==0) q[0].push(make_pair(0,s));
	cout<<"two queues size"<<endl;
	cout<<q[0].size()<<' '<<q[1].size()<<endl;
	while(!q[0].empty()||!q[1].empty()){
		cout<<"?"<<endl;
		//左手 
		if(!q[0].empty()){
			int x = q[0].top().second;
			cout<<"left now is"<<x<<endl;
			q[0].pop();
			if(!vis[x][0]){
				vis[x][0] = 1;//左手最短路已经找到
				int siz = e[x].size();
				for(int i=0;i<siz;i++){
					int v = e[x][i].second;
					if(!vis[v][0]){//左手，这种情况不用换手 
						if(hand[v]==1);
						else{
								if(d[v][0]>d[x][0]+e[x][i].first){
								d[v][0] = d[x][0]+e[x][i].first;
								q[0].push(make_pair(d[v][0],v));
							}
						}
					}
					if(!vis[v][1]){//右手，这种情况要换手
						if(hand[v]==0);
						else{
							if(d[v][1]>d[x][1]+e[x][i].first+hs){
								d[v][1] = d[x][1]+e[x][i].first+hs;
								q[1].push(make_pair(d[v][1],v));
							}
						}
					}
				}
			}
		}
		//右手
		if(!q[1].empty()){
			int x = q[1].top().second;
			cout<<"right now is"<<x<<endl;
			q[1].pop();
			if(!vis[x][1]){
				vis[x][1] = 1;
				int siz = e[x].size();
				for(int i=0;i<siz;i++){
					int v = e[x][i].second;
					if(!vis[v][0]){//左手，这种情况要换手 
						if(hand[v]==1);
						else{
							if(d[v][0]>d[x][0]+e[x][i].first+hs){
								d[v][0] = d[x][0]+e[x][i].first+hs;
								q[0].push(make_pair(d[v][0],v));
							}
						}
					}
					if(!vis[v][1]){//右手，这种情况不用换手
						if(hand[v]==0);
						else{
							if(d[v][1]>d[x][1]+e[x][i].first){
								d[v][1] = d[x][1]+e[x][i].first;
								q[1].push(make_pair(d[v][1],v));
							}
						}
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

