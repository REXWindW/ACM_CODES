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
typedef pair<ll,ll> Pll;
const int MAXN = 2077;
#define ft first
#define sd second
const double eps = 1e-5;

struct Edge{
	int s,t;//起点终点
	double dis;
};

Edge edges[MAXN*MAXN];
int n;
int sg[MAXN*MAXN];
Pll p[MAXN];//记录点坐标 
double d[MAXN][MAXN];//邻接矩阵
bool pvis[MAXN];//该点是否被访问过

inline double gdis(Pll a,Pll b){
	double res;
	res = (a.ft-b.ft)*(a.ft-b.ft)+(a.sd-b.sd)*(a.sd-b.sd);
	return sqrt(res);
}

int dfs_sg(int x){
	//cout<<"now at edge"<<x<<':'<<edges[x].s<<' '<<edges[x].t<<endl;
	int i;
	if(sg[x]!=-1) return sg[x];
	bool vis[MAXN]={0};
	int st = edges[x].t;
	rep(i,1,n){
		if(pvis[i]) continue;//被访问过的点 
		if(d[st][i]-edges[x].dis>eps){//一步比一步大
			pvis[i] = 1;//标记访问过的点 
			dfs_sg((st-1)*n+i);//走这条边 
			pvis[i] = 0;
			vis[sg[(st-1)*n+i]] = 1;
			//cout<<"nowsg = "<<sg[(st-1)*n+i]<<endl;
		}
	}
	int e;
	rep(i,0,n){
		if(!vis[i]){
			e=i;
			break;
		}
	}
	return sg[x]=e;
}

void solve(){
	cin>>n;
	rep(i,1,n){
		cin>>p[i].first>>p[i].second;
	}
	double maxx = -1;
	edges[0] = Edge{-1,1,0.0};
	rep(i,1,n){
		rep(j,1,n){
			d[i][j] = gdis(p[i],p[j]);
			edges[(i-1)*n+j] = Edge{i,j,d[i][j]};//ij边对应编号(i-1)*n+j
			maxx = max(maxx,d[i][j]);
		}
	}
	sg[0] = -1;
	rep(i,1,n*n){
		sg[i] = -1;
		if(abs(edges[i].dis-maxx)<eps) sg[i] = 0;//必败点 
	}
	pvis[1] = 1;
	dfs_sg(0);
	//rep(i,1,n*n){
	//	cout<<"sg of e"<<i<<"=="<<edges[i].s<<"to"<<edges[i].t<<'='<<sg[i]<<endl;
	//}
	rep(i,0,n*n) cout<<sg[i]<<' ';
	cout<<endl;
	if(sg[0]>0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	int z;
	cin>>z;
	while(z--) solve();
}
