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
//#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
#define INF 0x7fffffff

const int MAXN = 2e5+5;
char s[MAXN];
int a[MAXN];
int sum[5][MAXN];

void solve(){
	cin>>s;
	bool flag = 0;
	int n = strlen(s);
//	cout<<"n"<<n<<endl;
	sum[1][0]=sum[2][0]=sum[3][0]=0;
	rep(i,1,n){
		a[i]=s[i-1]-'0';
		for(int j=1;j<=3;j++) sum[j][i] = sum[j][i-1];
//		cout<<a[i]<<endl;
		sum[a[i]][i] = sum[a[i]][i-1] + 1;
	}
	int pxl = 1;
	int minn = INF;
	rep(i,3,n){
//		cout<<sum[1][i]-sum[1][pxl-1]<<' '<<sum[2][i]-sum[2][pxl-1]<<' '<<sum[3][i]-sum[3][pxl-1]<<endl;
		if(sum[1][i]-sum[1][pxl-1]&&sum[2][i]-sum[2][pxl-1]&&sum[3][i]-sum[3][pxl-1]){
			flag = 1;
			while(i-pxl>=2&&sum[1][i]-sum[1][pxl-1]&&sum[2][i]-sum[2][pxl-1]&&sum[3][i]-sum[3][pxl-1]){
				//cout<<"test"<<pxl<<' '<<i<<endl;
				minn = min(minn,i-pxl+1);pxl++;
			}
		}
	}
	if(!flag) cout<<0<<endl;
	else cout<<minn<<endl;
}

int main(){
	//freopen("outputs.txt","w",stdout);
	int z;
	cin>>z;
	while(z--) solve();
}

