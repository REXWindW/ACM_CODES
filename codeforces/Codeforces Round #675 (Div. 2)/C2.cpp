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
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 1e5+5;
const int med = 1e9+7;
string s;
int n;
int a[MAXN];
ll tn[MAXN];//10^n
ll jt[MAXN];//987654321
ll jj[MAXN];//1+2+3+4…………
void init(){
    tn[0] = 1;jt[0]=jj[0]=0;
    rep(i,1,n) tn[i] = tn[i-1]*10 % med;
    rep(i,1,n){
        jt[i] = (jt[i-1]*10%med + i)%med;//计算这种类似阶梯一样的数字
        jj[i] = (jj[i-1]+i)%med;
    }   
}
int main(){
    init();
    cin>>s;
    n = s.size();
	rep(i,0,n-1) a[i] = s[i]-'0';
    ll res = 0;
    rep(i,0,n){
        res += ( a[i]*(jt[n-i-1]+tn[n-i])%med ) * (jj[i]+1)  %med;//按位计算贡献
    }
    cout<<res<<endl;
}