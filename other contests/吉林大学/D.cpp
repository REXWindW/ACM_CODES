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

const int MAXN = 1e6+6;
ll yz[MAXN]; 
ll sum[MAXN];

void init(){
	yz[1] = 1;
	for(int i=2;i<MAXN;i++){
		yz[i] = i+1;//放上1和它自己 
	}
	int sqr = sqrt(MAXN);
	for(int i=2;i<=sqr;i++){
		for(int j=2;i*j<MAXN;j++){
			yz[i*j] += i;
			if(j>sqr) yz[i*j] += j;
		}
	} 
}

inline void cf_init(){
	sum[0] = 0;
	for(int i=1;i<MAXN;i++){
		sum[i] = sum[i-1] + yz[i];
	}
}


void solve(){
	int l,r;
	cin>>l>>r;
	cout<<sum[r]-sum[l-1]<<endl;
}

int main(){
	init();
	cf_init();
	int z;
	cin>>z;
	while(z--){
		solve();
	}
}

