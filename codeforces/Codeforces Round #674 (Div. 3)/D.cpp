#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
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
const int MAXN = 2e5+5;
typedef pair<ll,ll> pll;
ll a[MAXN];
ll sum[MAXN];
int n;
vector<pll> vec;
map<ll,ll> pre;
int main(){
	cin>>n;
	sum[0] = 0;
	rep(i,1,n){cin>>a[i];sum[i]=sum[i-1]+a[i];}
	pre[0] = 0;
	rep(i,1,n){
		if(pre[sum[i]]||sum[i]==0)
			vec.push_back(make_pair( pre[sum[i]]+1,i ));//把这段插入
		pre[sum[i]] = i;
	}
	sort(vec.begin(),vec.end());
	int siz = vec.size();
	//rep(i,0,siz-1) cout<<vec[i].first<<' '<<vec[i].second<<endl;
	if(siz==0){
		cout<<0<<endl;
		return 0;
	}
	ll cnt = 0;
	ll now = vec[0].second;
	rep(i,0,siz-1){
		if(vec[i].first>=now){
			cnt++;
			now = vec[i].second;
		}
		else{
			now = min(now,vec[i].second);
		}
	}
	cout<<cnt+1<<endl;
}