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

const int MAXN = 666;

int main(){
	int n;
	int a[MAXN];//������ 
	int dp[MAXN];//dp[i]������Ϊi�������еĽ�β���� 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=n;i++){
		int *px=lower_bound(dp+1,dp+1+n,a[i]);//�ҵ�����������С������λ�� 
		*px=a[i];//���룬���ԭλ���������򸲸ǣ���Ϊͬ������������β���ֽ�С���Ǹ� 
	}
	int now=1;
	while(dp[now]!=INF) now++; 
}

