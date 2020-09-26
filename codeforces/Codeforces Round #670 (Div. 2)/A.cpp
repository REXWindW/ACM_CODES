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

int n;
const int MAXN = 666;
int a[MAXN],cnt[MAXN];
void solve(){
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n){
		cnt[a[i]]++;
	}
	int px1 = 0;
	while(cnt[px1]>1) px1++;
	int px2 = px1;
	while(cnt[px2]>0) px2++;
	cout<<px1+px2<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--)solve();
}
