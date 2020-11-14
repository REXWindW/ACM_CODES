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
const int MAXN = 3e4+5;
#define int ll
int a[MAXN];
int cnt[MAXN];
int cntf[MAXN];
int n;
void solve(){
	memset(cnt,0,sizeof(cnt));
	memset(cntf,0,sizeof(cntf));
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	ll res = 0;
	if(2*a[2]-a[1]>=0) cnt[2*a[2]-a[1]]++;
	else cntf[-(2*a[2]-a[1])]++;
	rep(i,3,n){
		if(a[i]>=0) res+=cnt[a[i]];
		else res+=cntf[-a[i]];
		rep(j,1,i-1){
			int kk = 2*a[i]-a[j];
			if(kk>=0) cnt[kk]++;
			else cntf[-kk]++;
		}
	}
	cout<<res<<endl;
}

signed main(){
	int z;
	cin>>z;
	while(z--) solve();

}