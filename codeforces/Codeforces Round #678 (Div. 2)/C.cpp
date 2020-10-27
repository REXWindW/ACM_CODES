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
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int med = 1e7+5;
int n,x,pos;
//!a[i]<=n;
ll qpow(ll d,ll c){
	ll res = 1;
	while(c){
		if(c%2) res = res*d%med;
		d = d*d%med;
		c/=2;
	}
	return res;
}
void solve(){
	cin>>n>>x>>pos;
	//模拟
	int sma = 0,big = 0;
	//有多少个要小于等于x
	//有多少个要大于x
	ll res = 0;
	int l = 1,r = n;
	int mid;
	while(l<r){
		mid = (l+r)>>1;
		if(mid==pos){
			l = mid+1;//这里是一定要放x的,莫得选择
		}
		else if(mid<pos){//l要到mid+1上去
			l = mid+1;
			//a mid要小于等于x
			sma++;
		}
		else if(mid>pos){
			r = mid;
			//a mid要大于x
			big++;
		}
	}
	cout<<"smad"<<sma<<"big"<<big<<endl;
}

int main(){
	solve();
}