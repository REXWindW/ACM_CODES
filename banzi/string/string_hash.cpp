#include<iostream>
#include<algorithm> 
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

typedef pair<ull,ull> pll;
const int MAXN = 1e4+5;
const int M1 = 1e9+7;//第一个模数 
const int M2 = 1e9+9;//第二个模数 
const int b = 131;
int n;
pll a[MAXN];

pll gethash(string s){
	ull res1=0,res2=0;
	int siz = s.length();
	rep(i,0,siz-1){
		res1=(res1*b%M1+s[i])%M1;//i位乘以b^i
		res2=(res2*b%M2+s[i])%M2;//f(s)=Σ s[i] * b^i;
	}
	return make_pair(res1,res2);
}

int main(){
	cin>>n;
	string s;
	rep(i,1,n){
		cin>>s;a[i]=gethash(s);
	}
	sort(a+1,a+n+1);
	int res = 1;
	rep(i,2,n){
		if(a[i]!=a[i-1]) res++;
	}
	cout<<res<<endl;
}