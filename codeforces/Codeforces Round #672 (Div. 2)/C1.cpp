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
const int MAXN = 1e6+5;
int a[MAXN];
ll dp[MAXN][2];//0是-，1是+
ll maxx[2];//maxx0存之前0最大的，maxx1存之前1结尾最大的
int n;
void solve(){
	int hc;
	cin>>n>>hc;
	maxx[0]=maxx[1] = 0;
	rep(i,1,n){
		cin>>a[i];
		dp[i][0] = dp[i][1] = 0;
	}
	rep(i,1,n){
		dp[i][0] = maxx[1]-a[i];
		dp[i][1] = maxx[0]+a[i];
		maxx[0] = max(maxx[0],dp[i][0]);
		maxx[1] = max(maxx[1],dp[i][1]);
	}
	cout<<maxx[1]<<endl;
}
 
int main(){
	int z;
	cin>>z;
	while(z--) solve();
}
