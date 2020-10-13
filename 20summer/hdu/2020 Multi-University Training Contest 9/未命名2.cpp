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

ll a,b,k;
const double eps = 1e-12;

inline double cal(int k,double a){
	return 1/(a+k+1)+1/a;
}

void solve(){
	cin>>a>>b>>k;
	if(a>b) swap(a,b);
	double l = 1,r = 2;
	double now=0,mid;
	while(abs(now-1.0)>eps){
		mid = (l+r)/2;
		now = cal(k,mid);
		if(now>1.0) l = mid;
		else r = mid;
	}
	double alpha = mid;
	/*
	cout<<"alpha=="<<alpha<<endl;
	rep(i,1,15){
		cout<<(ll)floor(i*alpha)<<' '<<(ll)floor(i*(alpha+k+1))<<endl;
	}
	*/
	//if(floor((double)(b-a)/(k+1)*alpha)==floor(a)) cout<<0<<endl;
	//else cout<<1<<endl;
	int lb = 0,rb = 5e7+5;
	int midd;
	while(lb+1<rb){
		//cout<<lb<<' '<<rb<<endl;
		midd = (lb+rb)/2;
		if(floor(midd*alpha)>a) rb = midd;
		else lb = midd;
	}
	if(floor(lb*alpha)==a&&a+(k+1)*lb==b) cout<<0<<endl;
	else cout<<1<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

