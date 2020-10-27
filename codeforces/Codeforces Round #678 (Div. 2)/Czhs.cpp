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
#define int long long
//#define INF 0x7fffffff
const int med = 1e9+7;
const int MAXN = 1024;
int n,x,pos;
//!a[i]<=n;
//贴组合数板子
ll jc[MAXN];
ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%med;
        d=d*d%med;c>>=1;
    }return res;
}
inline ll niyuan(ll x){return qpow(x,med-2);}
void initjc(){//初始化阶乘
    jc[0] = 1;
    rep(i,1,MAXN-1) jc[i] = jc[i-1]*i%med;
}
inline int C(int n,int m){//n是下面的
    if(n<m) return 0;
    return jc[n]*niyuan(jc[n-m])%med*niyuan(jc[m])%med;
}
inline int A(int n,int m){//n是下面的
    if(n<m) return 0;
    if(n==0) return 1;
    return jc[n]*niyuan(jc[n-m])%med;
}
/*
int main(){
    initjc();
    int n,m;
    while(cin>>n>>m) cout<<C(n,m)<<endl;
}
*/
//组合数板子

void solve(){
	cin>>n>>x>>pos;
	//模拟
	int sma = 0,big = 0;
	//有多少个要小于等于x
	//有多少个要大于x
	ll res = 1;
	int l = 0,r = n;
	int mid;
	while(l<r){
		mid = (l+r)>>1;
		if(mid==pos){
			l = mid+1;//这里是一定要放x的,莫得选择
		}
		else if(mid<pos){//l要到mid+1上去
			l = mid+1;
			//a mid要小于等于x
			sma++;
		}
		else if(mid>pos){
			r = mid;
			//a mid要大于x
			big++;
		}
	}
    //cout<<"big"<<big<<"sma"<<sma<<endl;
    //cout<<"check"<<A(x-1,sma)<<' '<<A(n-x,big)<<' '<<A(n-sma-big-1,n-sma-big-1)<<endl;
    res *= A(x-1,sma);
    res%=med;
    res *= A(n-x,big);
    res%=med;
    res *= A(n-sma-big-1,n-sma-big-1);
    res%=med;
    cout<<res<<endl;
}

signed main(){
    initjc();
	solve();
}