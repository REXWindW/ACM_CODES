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
const int MAXN = 666;
int n,m;
int a[MAXN][MAXN];
int v[66];
void solve(){
	cin>>n>>m;
	rep(i,1,n){
		rep(j,1,m){
			cin>>a[i][j];
		}
	}
	int hn = (n+1)/2,hm = (m+1)/2;
	bool fn=0,fm=0;
	if(n%2) fn=1;
	if(m%2) fm=1;
	ll res = 0;
	int zs;
	rep(i,1,hn){
		rep(j,1,hm){
			if(fm&&fn&&i==hn&&j==hm) continue;
			v[1] = a[i][j];
			v[2] = a[n-i+1][j];
			v[3] = a[i][m-j+1];
			v[4] = a[n-i+1][m-j+1];
			sort(v+1,v+1+4);
			zs = v[2];
			rep(k,1,4){
				if(fn&&k==2&&i==hn) continue;
				if(fn&&k==4&&i==hn) continue;
				if(fm&&k==2&&j==hm) continue;
				if(fm&&k==4&&j==hm) continue;
				//cout<<"check"<<i<<' '<<j<<' '<<abs(zs-v[k])<<endl;
				res+=abs(zs-v[k]);
			}
		}
	}
	cout<<res<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}