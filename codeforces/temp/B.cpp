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

string s;
int n,m;
const int MAXN = 666;
int sum[2][MAXN];
void solve(){
	cin>>n>>m;
	cin>>s;
	sum[0][0] = 0;
	sum[1][0] = 0;
	rep(i,0,n-1){//qzh
		sum[1][i+1] = sum[1][i];
		sum[0][i+1] = sum[0][i];
		if(s[i]=='0') sum[0][i+1]++;
		else sum[1][i+1]++;
	}
	int l,r;
	while(m--){
		cin>>l>>r;
		int rs = s[r-1]-'0';
		int ls = s[l-1]-'0';
		if(sum[rs][n]-sum[rs][r]||sum[ls][l-1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}