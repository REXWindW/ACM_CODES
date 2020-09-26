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
typedef pair<int,int> pii;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e5+5;
int n;
pii p[MAXN];//点 

bool cmp(pii a,pii b){//根据y轴上截距从高到低排序 
	return (a.second-a.first)>(b.second-b.first); 
}

void solve(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&p[i].first,&p[i].second);//first 存t，second 存x 
	}//根据所在直线的高度来排序！ 
	sort(p+1,p+1+n,cmp);
	int countt = 1;
	int now = p[1].second-p[1].first;
	rep(i,2,n){
		if(p[i].second-p[i].first==now) continue;
		else{
			countt++;
			now = p[i].second-p[i].first;
		}
	}
	printf("%d\n",countt);
}

int main(){
	int z;
	scanf("%d",&z);
	while(z--) solve();
}

