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
int n;
vector<int> e[MAXN];
vector<int> we[MAXN];
vector<int> vec;
int b[MAXN];

void dfs(int x,int prev,int xsum){
	int siz = e[x].size();
	rep(i,0,siz-1){
		if(e[x][i]!=prev){
			dfs(e[x][i],x,xsum^we[x][i]);
		}
	}
	vec.push_back(xsum);
} 

int main(){
	cin>>n;
	int u,v,w;
	rep(i,1,n-1){
		cin>>u>>v>>w;
		e[u].push_back(v);
		we[u].push_back(w);
		e[v].push_back(u);
		we[v].push_back(w);
	}
	dfs(0,-1,0);
	sort(vec.begin(),vec.end());
	int pr = 0;
	int siz = vec.size();
	for(int i=0;i<siz;i++){
		b[i] = vec[i]^pr;
		pr = vec[i];
	}
	ll res = 0;
	int now = b[0];
	rep(i,1,siz){
		if(b[i]>=b[i-1]){
			now|=b[i];
		}
		else{
			res += now;
			now = 0;
		}
	}
	res += now;
	cout<<res<<endl;
}

