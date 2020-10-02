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
const int MAXN = 1e5+5;
int n,len;
int a[MAXN];
void solve(){
	scanf("%d%d",&n,&len);
	rep(i,1,n) scanf("%d",&a[i]);
	double t1=0,t2=0;//记录正反两人的时间
	int l = 0,r = n+1;//双指针
	a[0] = 0;a[n+1] = len;
    int v1=1,v2=1;
	while(l+1<r){//直到两人在相邻的加速点上
		if(t1+(double)(a[l+1]-a[l])/v1<t2+(double)(a[r]-a[r-1])/v2)
			t1+=(double)(a[l+1]-a[l])/v1,v1++,l++;
		else t2+=(double)(a[r]-a[r-1])/v2,v2++,r--;
	}
    if(t1>t2) swap(v1,v2);
    printf("%llf\n", max(t1,t2)+(a[r]-a[l]-v1*fabs(t1-t2))/(v1+v2));
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}