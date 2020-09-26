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

const double Pi = atan(1)*4;
double xita,aerfa;
const double beita = Pi/4;
double l,r;
int n;

void solve(){
	scanf("%d",&n);
	n*=2;
	double xj = 2*Pi/n;
	int x = abs(n/8*xj-Pi/4)<abs((n/8+1)*xj-Pi/4)?n/8:n/8+1;
	xita = 2*Pi/n*x;
	//cout<<n/4<<endl;
	aerfa = Pi - xita - beita;
	r = 0.5/sin(Pi/n);
	l = sin(aerfa)/sin(beita)*r;
	printf("%.9llf\n",l*sqrt(2));
}

int main(){
	int z; 
	scanf("%d",&z);
	while(z--) solve(); 
}

