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

const int MAXN = 100010;
char a[MAXN];
int b[MAXN];
const ll med =  1000000007;
ll res,ress;
ll sumb[MAXN];
ll pp[MAXN];

inline void init(){
	pp[0] = 1;
	for(int i=1;i<MAXN;i++){
		pp[i] = pp[i-1]*10%med;
	}
}

inline ll qpow(ll d,ll n){
	return pp[n];
}

inline int idx(char c){
	return c-'0';
}

void solve(){
	ll len,len2;
	cin>>a;
	res = 0;
	len = strlen(a);
	//res = (len2%med)*qpow(10,len2-1)%med;
	rep(i,0,len-1){
		b[len-i] = idx(a[i]);
	}
	sumb[0] = 0;
	rep(i,1,len){
		sumb[i] = (sumb[i-1]+b[i]*qpow(10,i-1)%med)%med;
		//记路最小i位数字med后是多少 
	}
	//计算阶段
	rep(i,0,len-1){
		len2 = len-i-1;
		ress = (len2%med)*qpow(10,len2-1)%med;
		ress = idx(a[i])*ress%med;//枚举后面的99999出现几个7； 
		res = (res+ress)%med;
		if(a[i]>'7'){
			ress = qpow(10,len2)%med;//当前i为7，剩下来几个随便动 
			res = (res+ress)%med;
		}
		//where problem is 
		else if(a[i]=='7'){
			ress = (sumb[len2]+1);
			res = (res+ress)%med; 
		}
		//where problem is
	}
	cout<<res<<endl;
}

int main(){
	init();
	//freopen("outputs.txt","w",stdout);
	int z;
	cin>>z;
	while(z--){
		solve();
	}
}
