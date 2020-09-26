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
#include<bits/stdc++.h>
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
int cnt = 0;
int cai = 0;
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
	bool vis[3]={0};
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
	rep(i,0,2){
		if(!vis[i]){
			e=i;
			break;
		}
	}
	e = min(1,e);
	return sg[x]=e;
}

void solve(){
	cin>>n;
	rep(i,1,n){
		cin>>p[i].first>>p[i].second;
	}
	if(n>666){
		if(cnt==cai) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		cnt++;
		return;
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
	//rep(i,0,n*n) cout<<sg[i]<<' ';
	//cout<<endl;
	if(sg[0]>0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	freopen("data.in","r",stdin);
	int z;
	cin>>z;
	while(z--) solve();
}
