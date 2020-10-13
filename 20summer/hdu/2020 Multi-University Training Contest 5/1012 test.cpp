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

const int MAXN = 1.5e6+5;
const int med = 998244353; 
ll jc[MAXN];
int n;

void init(){
	jc[1] = 1;
	rep(i,2,MAXN/2){
		jc[i] = jc[i-1]*i%med;
	}
}
//逆元板子 
void exgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}
ll inv(ll a, ll p){
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}

ll qpow(ll d,ll m){
	int res = 1;
	while(m!=0){
		if(m%2) res*=d;
		d = d*d;
		m/=2;
	}
	return res;
}

void solve(){
	vector<int> vecfz;
	vector<int> vecfm;
	ll sumfz = 0;//总情况数量
	cin>>n;
	vecfz.push_back(jc[n/2]);
	vecfm.push_back(1);
	sumfz = (sumfz+jc[n/2])%med; 
	rep(i,2,n/2-1){
		ll x = vecfz.back();
		x=x*(i+5-1)%med;
		vecfm.push_back(qpow(2,i-2)*vecfm[i-1]%med);
		vecfz.push_back(x);
		sumfz = (sumfz+x)%med;              
	} 
	vecfz.push_back(vecfz.back());
	vecfm.push_back(vecfm.back());
	sumfz = (sumfz+vecfz.back())%med;   
	rep(i,1,n/2){
		cout<<0;
		if(n!=1) cout<<' ';
	}
	rep(i,0,n/2) cout<<vecfz[i]/vecfm[i]<<' ';
	cout<<endl;
	rep(i,0,n/2){
		ll invq = inv(sumfz*vecfz[i]%med,med);
		cout<<invq*vecfz[i]%med;
		if(i!=n/2) cout<<' ';
	}
	cout<<endl;
}

int main(){
	init();
	int z;
	cin>>z;
	while(z--) solve();
}
