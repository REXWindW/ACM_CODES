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
typedef pair<int,int> pii;
const int MAXN = 666;
char a[MAXN][MAXN];
int n;
#define mkp make_pair
void solve(){
	cin>>n;
	rep(i,1,n){
		rep(j,1,n){
			cin>>a[i][j];
		}
	}
	vector<pii> res;
	if(a[1][2]==a[2][1]){
		if(a[n-1][n]==a[1][2]) res.push_back(mkp(n-1,n));
		if(a[n][n-1]==a[1][2]) res.push_back(mkp(n,n-1));
	}
	else if(a[n-1][n]==a[n][n-1]){
		if(a[1][2]==a[n-1][n]) res.push_back(mkp(1,2));
		if(a[2][1]==a[n-1][n]) res.push_back(mkp(2,1));
	}
	else{
		if(a[1][2]=='1') res.push_back(mkp(1,2));
		if(a[2][1]=='1') res.push_back(mkp(2,1));
		if(a[n-1][n]=='0') res.push_back(mkp(n-1,n));
		if(a[n][n-1]=='0') res.push_back(mkp(n,n-1));
	}
	int siz = res.size();
	cout<<siz<<endl;
	rep(i,0,siz-1){
		cout<<res[i].first<<' '<<res[i].second<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}