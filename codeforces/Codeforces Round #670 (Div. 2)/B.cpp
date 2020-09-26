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
int n;
ll a[MAXN];

void solve(){
	vector<ll> zs,fs;
	cin>>n;
	bool flag0 = 0;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]>0) zs.push_back(a[i]);
		else if(a[i]<0) fs.push_back(-a[i]);
		else flag0 = 1;
	}
	sort(zs.begin(),zs.end(),greater<ll>());
	sort(fs.begin(),fs.end(),greater<ll>());
	int siz = fs.size();
	vector<ll> fs2;
	for(int i=0;i+1<siz;i+=2){
		fs2.push_back(fs[i]*fs[i+1]);
	}
	if(zs.size()+fs2.size()*2<5||zs.size()==0){//tepan
		//cout<<"tp"<<zs.size()<<' '<<fs.size()<<endl;
		if(flag0){
			cout<<0<<endl;
			return ;
		}
		siz = fs.size();
		rep(i,0,siz-1){
			zs.push_back(fs[i]);
		}
		sort(zs.begin(),zs.end(),less<ll>());
		ll res = 1;
		rep(i,0,4){
			res*=zs[i];
		}
		cout<<-res<<endl;
		return;
	}
	siz = fs2.size();
	ll res = 1;
	ll maxx = -INF;
	rep(i,0,min(2,siz)){
		res = 1;
		rep(j,0,i-1) res*=fs2[j];
		int rest = 5-i*2;
		if(rest>zs.size()) continue;
		rep(j,0,rest-1) res*=zs[j];
		maxx = max(maxx,res);
	}
	cout<<maxx<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}

