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

const double eps = 1e-7;
const double G = 6.67430e-11;
int ma,mb,d,t;

void solve(){
	scanf("%d%d%d%d",&ma,&mb,&d,&t);
	double l3 = d*d*d - 3*G*(ma+mb)*t;
	double le = 0,ri = sqrt(l3);
	double mid;
	while(ri-le>=eps){
		mid = (le+ri)/2;
		if(mid*mid*mid>=l3) ri = mid;
		else if(mid*mid*mid<l3) le = mid;
	}
	printf("%.10llf\n",(le+ri)/2);
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

