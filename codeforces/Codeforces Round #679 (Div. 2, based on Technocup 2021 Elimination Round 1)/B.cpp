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

const int MAXN = 514;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int p[MAXN];
int vis[MAXN*MAXN];
int n,m;
void solve(){
	cin>>n>>m;
	rep(i,1,n)
		rep(j,1,m){
			vis[(i-1)*m+j]=0;//清空vis
			cin>>a[i][j];
		}
	rep(i,1,m)
		rep(j,1,n) cin>>b[i][j];
	//读入完成
	rep(i,1,n){
		vis[ a[i][1] ] = 1;
	}
	int bj=0;
	rep(i,1,m){
		if(vis[ b[i][1] ]){
			bj = i;break;
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			if(b[bj][i]==a[j][1]) p[i] = j;
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			cout<<a[p[i]][j]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}