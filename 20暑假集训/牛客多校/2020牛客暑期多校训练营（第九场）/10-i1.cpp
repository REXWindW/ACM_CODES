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

int a[MAXN];
int b[MAXN];
int n;

void solve(){
	int cnt = 1;
	rep(i,1,n){
		rep(j,i+1,n){
			a[cnt] = i;
			b[cnt] = j;
			if(i>1&&j==i+1){
				int k = 1;
				while(a[k]!=i-1||b[k]!=j) k++;
				k++;
				//cout<<"ij"<<i<<' '<<j<<' '<<k<<endl; 
				swap(a[k],a[cnt]);
				swap(b[k],b[cnt]);
				repb(c,cnt,k+2){
					swap(a[c],a[c-1]);
					swap(b[c],b[c-1]);
				}
			}
			cnt++;
		}
	}
	int nn = (n*(n-1))/2;
	rep(i,1,nn){
		cout<<a[i]<<' '<<b[i]<<endl;
	}
}

int main(){
	while(cin>>n) solve();
}

