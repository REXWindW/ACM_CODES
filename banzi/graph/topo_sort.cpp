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

const int MAXN = 110;

vector<int> e[MAXN];
int n,m;
int indg[MAXN];

void solve(){
	for(int i=1;i<=n;i++) {indg[i]=0;e[i].clear();}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		e[u].push_back(v);
		indg[v]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(indg[i]==0) q.push(i);//找到入度为0的点
	vector<int> res;//储存结果的向量
	int u;
	while(!q.empty()){//BFS
		u = q.front();
		q.pop();
		res.push_back(u);
		for(auto v:e[u]){
			if(--indg[v]==0)q.push(v);
			//删掉当前点u，点v的入度--
			//这一步的目的是找到新的入度为0的节点，推入队列Q
		}
	}
	if(res.size()==n){//如果这个图无环的话，说明可以进行拓扑排序
		for(int i=0;i<n;i++){//输出结果
			cout<<res[i]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	while(cin>>n>>m&&!(n==0&&m==0)) solve();
}
//Uva10305
//https://vjudge.net/problem/UVA-10305