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

const ll p = 99824435;


ll ji[MAXN];
ll ou[MAXN];
ll ji_inv[MAXN]; 
ll ou_inv[MAXN];
ll inv[MAXN];

init(){
	inv[1] = 1;
	for (int i = 2; i <= MAXN; ++i) inv[i] = (long long)(p - p / i) * inv[p % i] % p;
	ji[1] = 1;
	ou[2] = 2;
	ji_inv[1] = inv[1];
	ou_inv[2] = inv[2];
	for(int i=3;i<=n;i+=2){
		ji[i] = ji[i-2]*i%p;
		ji_inv[i] = ji_inv[i-2]*inv[i]%p;
	}
	for(int i=4;i<=n;i+=2){
		ou[i] = ou[i-1]*i%p;
		ou_inv[i] = ou_inv[i-2]*inv[i]%p;
	}
}

int main(){

}

