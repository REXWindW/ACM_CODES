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
const int MAXN = 1e6;

bool vis[MAXN];
int f[MAXN]={0};
int n;

void init(){//找最小因子，并且标记出合数 
	int sqr = sqrt(MAXN);
	for(int i=2;i<sqr;i++){
		if(f[MAXN])continue;
		for(int j=2;i*j<MAXN;j++){
			if(!f[i*j]) f[i*j] = i;
		}
	}
}

int main(){
	init();
	int countt = 0;
	for(int i=500;i<=1000;i++)
		if(f[i]==0) countt++;
	cout<<countt<<endl;
}

