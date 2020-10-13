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

const int MAXN = 250; 

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int sta;
int n,k;

void solve(){
	cin>>n>>k;
	if(n==1||k==1||2*n*(n+1) % k != 0){
		cout<<-1<<endl;
		return;
	}
	int co = 1;
	rep(i,1,n){
		rep(j,1,n){
			a[i][j] = co;
			co = co%k+1;
		}
		rep(j,1,n+1){
			b[j][i] = co;
			co = co%k+1;
		}
	}
	rep(j,1,n){
		a[n+1][j] = co;
		co = co%k+1;
	}
	rep(i,1,n+1){
		rep(j,1,n){
			cout<<a[i][j];
			if(j!=n) cout<<' ';
		}
		cout<<endl;
	}
	//cout<<"testttt"<<endl;
	rep(i,1,n+1){
		rep(j,1,n){
			cout<<b[i][j];
			if(j!=n) cout<<' ';
		}
		cout<<endl;
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}
