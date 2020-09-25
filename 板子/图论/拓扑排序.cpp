#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
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
#define LINF 1ll<<60
const int MAXN = 2e5+10;
typedef pair<int,ll> pli;
vector<pli> e[MAXN];//first是目标的点，second是距离dis 
bool vis[MAXN];
ll d[MAXN];
int n,m,s,t;

void dijkstra(){
	rep(i,1,n){
		d[i] = LINF;
		vis[i] = 0;
	}
	d[s] = 0;
	priority_queue< pli,vector<pli>,greater<pli> >q;//first存d[x],second存x的编号 
	q.push(make_pair(0,s));
	while(!q.empty()){//进行类似bfs的操作 
		int now = q.top().second;
		q.pop();
		if(vis[now])continue;//可以看到下面的操作是都先推进去的，所以可能重复遇到now点 
		vis[now] = 1;
		int siz = e[now].size();
		for(auto x:e[now]){//遍历now的所有边 
			int v = x.second;//到达的点
			if(d[v]>d[now]+x.first){
				d[v] = d[now] + x.first;
				q.push(make_pair(d[v],v));//推入优先队列 
			} 
		}
	}
}

int main(){
	cin>>n>>m>>s;
	int u,v;
	ll dis;
	rep(i,1,m){
		cin>>u>>v>>dis;
		e[u].push_back(make_pair(dis,v));
		//e[v].push_back(make_pair(u,dis));//双向通行的情况 
	}
	dijkstra();
	rep(i,1,n){
		cout<<d[i];//输出到各个点的最短路径 
		if(i!=n) cout<<' ';
	}
} 
//Uva10305 https://vjudge.net/problem/UVA-10305