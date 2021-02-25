#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f

const int med = 998244353;
ll qpow(ll d,ll c){//快速幂
	ll res = 1;
	while(c){
		if(c&1) res=res*d%med;
		d=d*d%med;c>>=1;
	}return res;
}
ll n;
void solve(){
	cin>>n;
	ll t = (n-2)/2;
	ll a1 = qpow(2,n-t-3+1);
	ll x = a1*(qpow(2,t)-1)%med;
	ll ys = (n-t)%4;
	if(ys==2||ys==0){
		x+=a1;
	}
	else if(ys==1){
		x+=2*a1;
	}
	cout<<x<<endl;
	cout<<"yushu"<<ys<<endl;
}

int main(){
	solve();
}