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

const int MAXN = 2e5+5;

typedef pair<int,int>pii;
typedef pair<double,double>pdd;

pii rob[MAXN];
pii robb[MAXN];
pdd p[MAXN];
int n;

void solve(){
	cin>>n;
	rep(i,1,n) cin>>rob[i].first>>rob[i].second;
	sort(rob+1,rob+1+n,greater<pii>());
	int nn=0;
	rep(i,1,n){
		if(rob[i]==rob[i+1]){
			while(rob[i]==rob[i+1]&&i<=n)i++;
		}
		else robb[++nn] = rob[i];
	}
	for(int i=1;i<=n;i++){
		cout<<robb[i].first<<' '<<robb[i].second<<endl;
	}
	cout<<endl;
}

int main(){
	cin>>z;
	while(z--) solve();
}

