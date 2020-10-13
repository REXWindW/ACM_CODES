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

const ll med = 1e9+7;

ll l,r,t,m;
ll n,k;

int main(){
	cin>>n>>k;
	ll res = 0;
	l = 1;
	while(l<=k){
		t = n/l;
		if(t==0) r = k;
		else r = n/t;
		//cout<<"divided by"<<l<<"to"<<r<<":"<<n/l<<' '<<n/r<<endl;
		res = (res + (n/l)*(min(r,k)-l+1))%med;
		l = r+1;
	}
	//cout<<"before res"<<res<<endl;
	//cout<<"yu 1"<<endl;
	l = 2;
	//n=n+k-1;//这句有问题的，k应该是变化的 
	while(l<=k){
		m = (n+l-1)/l;//向上取整
		if(m==1) r = k;
		else r = (n-1)/(m-1);
		//cout<<"lr"<<l<<' '<<r<<endl;
		//cout<<"divided by"<<l<<"to"<<r<<":"<<(n+l-1)/l<<endl;
		res = (res + (n+l-1)/l*(min(r,k)-l+1))%med;
		l = r+1;
	}
	cout<<res<<endl;
}

