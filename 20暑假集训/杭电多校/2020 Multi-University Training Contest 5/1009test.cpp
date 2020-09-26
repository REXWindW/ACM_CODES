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

ll qpow(ll d,ll m){
	int res = 1;
	while(m!=0){
		if(m%2) res*=d;
		d = d*d;
		m/=2;
	}
	return res;
}

double C(int d,int u){
	double res = 1;
	for(int i=0;i<u;i++){
		res*=d-i;
		res/=i+1;
	}
	return res;
}

int n;

int main(){
	while(cin>>n){
		double res = 0;
		rep(x,0,n){//Ã¶¾ÙxÇóºÍ 
			res+=C(n,x)/qpow(2,x);
		}
		cout<<"#case"<<n<<": "<<res<<endl;
	}
}

