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

const int MAXN = 1e6+5;
const int med = 998244353;

ll a[MAXN];
ll b[MAXN];
ll sumb[MAXN];
ll sum[MAXN];
ll res,ress;
int n;

inline int getqz(int p){
	return n-p+1;
}

inline int getqz2(int p){
	return p;
}

int main(){
	res = 0;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	sumb[0] = sum[0] = 0;
	rep(i,1,n){
		cin>>b[i];
		sumb[i] = (sumb[i-1]+ b[i]*getqz(i) )%med;
		sum[i] = ( sum[i-1] + b[i] )%med ;
	}
	rep(i,1,n){
		ll sb = (sumb[n]+med-sumb[i-1])%med;
		ll s = (sum[n]+med-sum[i-1])%med;
		ress =a[i] * ((s*i-1 + sb)%med) %med ;//attention!
		res += ress%med;
	}
	cout<<res<<endl;
}

