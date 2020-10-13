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
int n,t;
vector<int> e[MAXN];
int tpoint;//t时刻gh所在的点 
int to_n[MAXN]={0};
int res,resp;
int dis1;

bool dfs1(int now,int prev){//找到n的路径 
	if(now==n) return 1;
	int road_to_n = 0;
	for(auto v:e[now]){
		if(v==prev) continue;
		if(dfs1(v,now)){
			road_to_n = v;
			break;
		}
	}
	to_n[now] = road_to_n;
	return road_to_n!=0;
}

int dfs2(int now,int prev){
	//cout<<"now is"<<now<<endl;
	int maxx = -1;
	for(auto v:e[now]){
		if(v==prev||v==to_n[now]) continue;
		int d = dfs2(v,now);
		maxx = max(d,maxx);
	}
	return maxx+1;
}

void dfs3(int now,int prev,int steps){//可以往to_n方向走，但是要计算steps; 
	int jbres;
	if( dis1<=3*steps ){//被抓到的情况 
		return;
	}
	int dist2 = dfs2(now,prev);//从这个点开始dfs2;
	int dist1 = dis1-3*steps;//og和gh之间现在的距离 
	if(dist2>=dist1) jbres = dist1;
	else jbres = (dist1+dist2+1)/2;
	jbres+=steps; 
	if(jbres>res){
		res = jbres;
		//resp = now;
	}
	//cout<<"trzx"<<now<<endl;
	//cout<<dist1<<' '<<dist2<<endl;
	//cout<<"jbres"<<jbres<<endl;
	dfs3(to_n[now],now,steps+1);//铤而走险
}

int main(){
	cin>>n>>t;
	int u,v;
	rep(i,1,n-1){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,-1);
	int pls = 1;
	int tt = t;
	while(tt--&&pls!=n){
		pls = to_n[pls];
	}
	int fy = 1;
	dis1 = 0;
	while(fy!=n){
		fy = to_n[fy];
		dis1++;
	}
	dis1-=t;
	if(pls==n){cout<<0<<endl;return 0;}
	res = 0;
	dfs3(pls,-1,0);//这里设置成-1细节 
	//cout<<"resp=="<<resp<<endl;
	cout<<res<<endl;
}

