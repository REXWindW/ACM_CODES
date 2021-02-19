#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int med = 1e9+7;
const int MAXN = 114514;

vector<int> e[MAXN];
int rt = 1;

ll qpow(ll d,ll c){//快速幂
	ll res = 1;
	while(c){
		if(c&1) res=res*d%med;
		d=d*d%med;c>>=1;
	}return res;
}

inline ll niyuan(ll x){return qpow(x,med-2);}

struct node{
	ll x,y,fh;
	node(){
		x=0,y=0,fh=1;
	}
}a[MAXN];

ll b[MAXN];
int n;
char fh[MAXN];
void dfs(int now,int pre){
	if(fh[now]=='+'){
		a[now].x=a[pre].x+a[pre].fh*a[pre].y;
		a[now].x%=med;
		a[now].y=b[now];
		a[now].fh=1;
	}
	else if(fh[now]=='-'){
		a[now].x=a[pre].x+a[pre].fh*a[pre].y;
		a[now].x%=med;
		a[now].y=b[now];
		a[now].fh=-1;
	}
	else if(fh[now]=='*'){
		a[now].x=a[pre].x;
		a[now].fh=a[pre].fh;
		a[now].y=a[pre].y*b[now];
		a[now].y%=med;
	}
	else if(fh[now]=='/'){
		a[now].x=a[pre].x;
		a[now].fh=a[pre].fh;
		a[now].y=a[pre].y*niyuan(b[now]);
		a[now].y%=med;
	}
	a[now].x%=med;
	a[now].y%=med;
	a[now].x=(a[now].x+med)%med;
	a[now].y=(a[now].y+med)%med;
	//cout<<"check"<<now<<' '<<a[now].x<<' '<<a[now].y<<endl;
	for(auto v:e[now]){
		dfs(v,now);
	}
}

void solve(){
	cin>>n;
	rep(i,1,n) cin>>b[i];
	int hc;
	rep(i,2,n){
		cin>>hc;
		e[hc].push_back(i);
	}
	fh[1]='+';
	rep(i,2,n){
		cin>>fh[i];
	}
	dfs(rt,0);
	ll res = 0;
	rep(i,1,n){
		res = a[i].x+a[i].fh*a[i].y;
		res%=med;
		res=(res+med)%med
		cout<<res<<' ';
	}
	cout<<endl;
}

signed main(){
	solve();
}