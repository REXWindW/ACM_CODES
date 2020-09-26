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
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 110;

int n; 
int d[MAXN];
int s[MAXN];

int main(){
	scanf("%d",&n);
	int maxx = 0;
	rep(i,1,n){
		scanf("%d",&d[i]);
		maxx = max(maxx,d[i]);
	}
	for(int j=1;j<=n;j++){
		s[j] = (1ll*50*d[j]+maxx-1)/maxx;
		
		printf("+");
		for(int i=1;i<=s[j];i++) printf("-");
		printf("+\n");
		
		printf("|");
		for(int i=1;i<=s[j]-1;i++) printf(" ");
		if(s[j]>0){
			if(d[j]==maxx) printf("*");
			else printf(" ");
		}
		printf("|");
		printf("%d",d[j]);
		printf("\n");
		
		printf("+");
		for(int i=1;i<=s[j];i++) printf("-");
		printf("+\n");
	}
}

