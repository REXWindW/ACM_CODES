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

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

int n,m;

void solve(){
	vector<int> vec;
	cin>>n>>m;
	if(m>n) swap(m,n);
	int d = n-m;
	if(n%m==0){//最简单一种情况：n==m; 
		cout<<n<<endl;
		rep(i,1,n){
			cout<<m;
			if(i!=n) cout<<' ';
		}
		cout<<endl;
		return;
	}
	int gcdd = gcd((n-m)*m,d);
	if(gcdd>m){
		cout<<"check"<<endl;
		gcdd = gcd(m,d);
	}
	//cout<<"gcdd=="<<gcdd<<endl;
	rep(i,1,m){
		vec.push_back(m);
	}
	rep(i,1,m*d/gcdd){
		vec.push_back(gcdd);
	}
	int siz = vec.size();
	cout<<siz<<endl;
	rep(i,0,siz-1){
		cout<<vec[i];
		if(i!=siz-1) cout<<' ';
	} 
	cout<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve(); 
}

