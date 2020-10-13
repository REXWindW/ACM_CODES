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

const int MAXN = 1e5+5;
const int Mod = 1e9+7;
int n,m;
bool color[MAXN]; 
//���鼯���� 
int cnt1[MAXN],cnt0[MAXN];
ll sum1[MAXN],sum0[MAXN];//��������ǰ�ڵ�ľ���� 
ll res[MAXN];
int par[MAXN];//��¼���׽ڵ� 
int rk[MAXN];//��¼����,���ڵ�(���Ƚڵ�)�ǲ��ǲ����ȥ��  
vector<Pll> e[MAXN];//��� 

void init(){
	for(int i=1;i<=n;i++){
		res[i]=sum1[i]=sum0[i]=0;
		cnt1[i]=cnt0[i] = 0;
		if(color[i]==1) cnt1[i]++;
		else cnt0[i]++;
		e[i].clear();
		par[i]=i;
		rk[i]=0;
	}
} 
int find(int x){//��ѯ��������ͬʱ����·��ѹ�� 
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);//���ܾ���,�ڵݹ��ѯ���ڵ��ͬʱ·iѹ�� 
} 
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;///����Ѿ�������ͬ�����ȣ��򲻽��кϲ�����
	if(rk[x]<rk[y]) par[x]=y;//y����x���ߵ��������x��Ϊy�Ķ��ӽڵ� 
	else{//y��x�ߣ���ͬ�ߵ�����£���y��Ϊx�Ķ��ӽڵ� 
		par[y]=x;
		if(rk[x]==rk[y]) rk[x]++;//����ϲ�������ͬ�ߣ���ϲ�������+1; 
	} 
}

void add_edge(int u,int v,ll w){
	e[u].push_back(make_pair(v,w));
	e[v].push_back(make_pair(u,w));
}

int d0,d1;

void dfs(int now,int prev){
	cout<<"now is in"<<now<<endl;
	for(auto x:e[now]){	
		if(x.first==prev) continue;
		dfs(x.first,now);
		cnt1[now]+=cnt1[x.first];
		cnt0[now]+=cnt0[x.first];
		sum1[now] = (sum1[now] + cnt1[x.first]*x.second%Mod)%Mod;
		sum0[now] = (sum0[now] + cnt0[x.first]*x.second%Mod)%Mod;
		sum1[now] = (sum1[now]+sum1[x.first])%Mod;
		sum0[now] = (sum0[now]+sum0[x.first])%Mod;
	}
	for(auto x:e[now]){
		if(x.first==prev) continue;
		res[now] = (res[now]+ ( sum1[x.first]*(cnt0[now]-cnt0[x.first]) )%Mod )%Mod;
		if(color[now]==1){
			res[now] = (res[now]+cnt0[x.first]*x.second%Mod+sum0[x.first] )%Mod;
		}
		else if(color[now]==0){
			res[now] = (res[now]+cnt1[x.first]*x.second%Mod+sum1[x.first] )%Mod;
		}
		res[now] = (res[now]+res[x.first])%Mod;
	}
	cout<<"res"<<now<<"=="<<res[now]<<endl;
}

void solve(){
	cout<<"v2"<<endl;
	cin>>n>>m;
	rep(i,1,n) cin>>color[i];
	init();
	int now = 2;
	int u,v; 
	rep(i,1,m){//O(n)ת��Ϊ���ϵ����� 
		cin>>u>>v;
		if(find(u)==find(v)) continue;//���ñ� 
		merge(u,v);
		add_edge(u,v,now);//�ӱ�
		now = now*2%Mod;
	}
	d0 = d1 = 0;
	dfs(1,-1);
	cout<<res[1]<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

