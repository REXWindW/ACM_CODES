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

ll n,k;
ll a[MAXN],b[MAXN];
ll lb[MAXN],rb[MAXN];

void solve(){
	cin>>n>>k;
	rep(i,1,n) cin>>a[i]>>b[i];
	ll l = a[1],r = b[1];
	lb[1] = a[1];rb[1] = b[1];
	rep(i,2,n){
		l=l-k;r=r+k;//×îÔ¶Î»ÖÃ
		l = max(l,a[i]);
		r = min(r,b[i]);
		if(l>r){
			cout<<"NO"<<endl;
			return;
		}
		lb[i] = l;rb[i] = r;
	}
	nowp = lb[n];
	vector<ll>vec;
	vec.push_back(nowp);
	repb(i,n-1,1){
		l = lb[n]-k;
		r = lb[n]+k;
		l = max(l,a[i]);
		r = min(r,b[i]);
		nowp = l;
		vec.push_back(nowp);
	}
	int siz = vec.size();
	repb(i,siz-1,0){
		cout<<vec[i];
		if(i!=0) cout<<' ';
	}
}

int main(){
	int z;
	cin>>z;
	while(z--) solve(); 
}

