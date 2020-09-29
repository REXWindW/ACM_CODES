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

const int MAXN = 666;
int a[MAXN][3][3];
bool flag;
bool flag2;
int aa,bb,cc;
int n,m;
inline bool dc(int x,int y){
	bool res = 1;
	if(a[x][1][1]==a[y][1][1]&&a[x][2][2]==a[y][2][2]);
	else res = 0;
	if(a[x][1][2]==a[y][2][1]&&a[x][2][1]==a[y][1][2]);
	else res = 0;
	return res;
}
void solve(){
	flag = flag2 = 0;
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i][1][1]>>a[i][1][2]>>a[i][2][1]>>a[i][2][2];
		if(a[i][1][2]==a[i][2][1]) flag = 1;
	}
	if(m%2){
		cout<<"NO"<<endl;
		return ;
	}	
	rep(i,1,n){
		rep(j,1,n){
			if(dc(i,j)){
				flag2 = 1;
				break;
			}
		}
	}
	//cout<<flag<<' '<<flag2<<endl;
	if(flag&&flag2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}