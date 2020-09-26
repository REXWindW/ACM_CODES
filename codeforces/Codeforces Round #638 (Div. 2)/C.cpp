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

const int MAXN = 1e5+5;
char a[MAXN];
int n,k;

void solve(){
	cin>>n>>k;
	cin>>a;
	sort(a,a+n);
	if(a[0]==a[n-1]){
		string res((n+k-1)/k,a[0]);
		cout<<res<<endl; 
	}
	else if(a[0]==a[k-1]){
		if(a[k]!=a[0]&&a[k]==a[n-1]){
			cout<<a[0];
			string res((n-1)/k,a[k]);
			cout<<res<<endl;
		}
		else cout<<a+k-1<<endl;
	}
	else{
		cout<<a[k-1]<<endl; 
	}
} 

int main(){
	int z;
	cin>>z;
	while(z--)solve(); 
}

