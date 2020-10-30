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
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 1e5+5;
ll a[8];
ll b[MAXN];
int n;
void solve(){
	int m = 6;
	rep(i,1,m) cin>>a[i];
	sort(a+1,a+1+m);
	m = unique(a+1,a+1+m)-a-1;
	cin>>n;
	rep(i,1,n) cin>>b[i];
	sort(b+1,b+1+n);
	n = unique(b+1,b+1+n)-b-1;
	//读入两个数组，排序去重
	ll minx,maxx,minn = 1ll<<62;
	rep(i,1,n){
		rep(j,1,m){
			maxx = 0;
			minx = b[i]-a[j];
			if(b[1]-a[1]<minx) continue;
			rep(k,1,m){
				//注意琴格从1开始
				//b[?]-a[k]>=minx 变形 b[?]>=minx+a[k]
				int px = lower_bound(b+1,b+1+n,minx+a[k])-b-1;
				//找到最后一个可以用a[k-1]但一定用不了a[k]的
				maxx = max(b[px]-a[k-1],maxx);
				
			}
			repb(k,m,1){
				if(b[n]-a[k]>=minx){//和音符中的最大值进行比较,并且找一根尽可能大的琴弦
					maxx = max(maxx,b[n]-a[k]);
					break;
				}
			}
			minn = min(maxx-minx,minn);
		}
	}
	cout<<minn<<endl;
}

int main(){
	solve();
}