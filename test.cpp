#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
inline ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
//这里其实是位运算实现的辗转相除法求最大公因数
ll a,b,c,d;
void solve(){
	cin>>a>>b>>c>>d;
	ll fz = a*c;
	ll fm = b*d;
	ll gcdd = gcd(fz,fm);//求分子和分母的最大公因数
	cout<<fz/gcdd<<' '<<fm/gcdd<<endl;
}
int main(){
	int z;
	cin>>z;
	while(z--) solve();
}