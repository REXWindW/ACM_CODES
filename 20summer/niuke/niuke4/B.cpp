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
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e6+5;
const ll med = 1000000007; 

bool hs[MAXN]={0};
vector<int>yz[MAXN];
ll c,n;

ll qpow(ll d,ll m){//底数和幂次数
	ll res = 1;//构造E单位矩阵
	while(m){
		if(m&1) res=res*d%med;
		d=d*d%med;
		m>>=1;
	}
	return res%med;
}

void init(){
	int sqr = sqrt(MAXN);
	for(int i=2;i<=sqr;i++){
		if(hs[i]) continue;
		for(int j=2;i*j<MAXN;j++){
			hs[i*j] = 1;
		}
	}
	for(int i=2;i<=sqr;i++){
		if(hs[i]) continue;
		for(int j=2;i*j<MAXN;j++){
			yz[i*j].push_back(i);
			if(!hs[j]) yz[i*j].push_back(j);
		}
	}
} 

inline void solve(){
	scanf("%lld%lld",&n,&c);
	if(hs[n]==0){
		printf("%lld\n",n);
		return;
	}
	ll countt = 0;
	for(auto div:yz[n]){
		while(n%div==0){n/=div;countt++;}
		if(n==1) continue;
	}
	printf("%lld\n",qpow(c,countt));
}

int main(){
	int z;
	init();
	scanf("%d",&z);
	while(z--) solve();
}

