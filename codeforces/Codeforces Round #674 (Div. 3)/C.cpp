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
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
ll t;
void solve(){
	cin>>t;
	if(t==1){
		cout<<0<<endl;
		return;
	}
	ll sqrtt = sqrt(t);
	ll res = (sqrtt-1)*2;
	if(sqrtt*sqrtt<t){
		res++;
		if(t-sqrtt*sqrtt>sqrtt)res++;
	}
	cout<<res<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}