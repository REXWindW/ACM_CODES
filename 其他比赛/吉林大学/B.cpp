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

const int MAXN = 1e6+5;
ll a[MAXN];
ll r[MAXN][5];
const int med = 5;
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<5;j++) r[i][j] = -1;
	}
	for(int i=0;i<=4;i++) r[0][i] = -1;
	r[0][0] = 0;//start point
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			if(r[i-1][j]==-1) continue;
			r[i][j] = max(r[i][j],r[i-1][j]);
			r[i][(j+a[i])%med] = max(r[i][(j+a[i])%med],r[i-1][j]+a[i]);
		}
	}
	cout<<r[n][0]<<endl;
}
