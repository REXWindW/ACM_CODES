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

ll a,b,c,d;

void solve(){
	cin>>a>>b>>c>>d;
	ll tot=0;
	a-=b;tot+=b;
	if(a<=0) {cout<<tot<<endl;return;}
	if(c<=d) {cout<<-1<<endl;return;}
	ll tt = c-d;
	ll countt = (a+tt-1)/tt;
	tot += countt * c;
	cout<<tot<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--)solve();
}

