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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 5e5+5;

vector<int> e[MAXN];
ll size[MAXN];
ll res,maxx;
int n;

int dfs(int now){
	size[now] = 1;
	for(auto v:e[now]){
		size[now]+=dfs(v);	
	}
	res+=size[now];
	return size[now];
}

void dfs2(int now,ll sum){
	if(e[now].empty()){
		maxx = max(maxx,sum);
		return;
	}
	for(auto v:e[now]){
		dfs2(v,sum+n-size[v]);
	}
}

void solve(){
	res = maxx = 0;
	cin>>n;
	int fa;
	rep(i,1,n) e[i].clear();
	rep(i,2,n){
		size[i]=1;
		cin>>fa;
		e[fa].push_back(i);
	}
	dfs(1);
	//rep(i,1,n) cout<<size[i]<<' ';
	//cout<<endl;
	dfs2(1,0);
	cout<<res+maxx<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

