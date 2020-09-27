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

const int MAXN = 2e5+5;
int a[MAXN];
int dp[MAXN];
int n;

void solve(int z){
	cin>>n;
	dp[0] = INF;
	rep(i,1,n){
		cin>>a[i];
		dp[i] = INF;
	}
	dp[1] = a[1];
	dp[2] = a[1]+a[2];
	rep(i,3,n){
		//我走1
		dp[i] = dp[i-2]+a[i];//走1
		dp[i] = min(dp[i],dp[i-3]+a[i-1]+a[i]);//走2
		//我走2
		if(i<4) continue;
		dp[i] = min(dp[i],dp[i-3]+a[i]);//走1
		dp[i] = min(dp[i],dp[i-4]+a[i]+a[i-1]);//走2
	}
	int res = dp[n];
	if(n>2) res = min(res,dp[n-2]);//最后一步是我走2的情况
	if(n>1) res = min(res,dp[n-1]);//最后一步是我走1的情况
	//rep(i,1,n) cout<<dp[i]<<' ';
	//cout<<endl;
	//cout<<"res"<<z<<' ';
	cout<<res<<endl;
}

int main(){
	int z;
	cin>>z;
	rep(i,1,z) solve(i);
}