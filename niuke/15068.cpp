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
inline ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
inline ll lcm(ll a,ll b){ return a/gcd(a,b)*b;}
//#define INF 0x7fffffff

const int MAXN = 1e5+5;
ll m[MAXN],c[MAXN];
int n;
void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){//不同的是，这里的d使用引用来实现 
	if(!b){d=a;x=1;y=0;}
	else{Exgcd(b,a%b,d,y,x);y-=x*(a/b);}//先交换了xy的位置，实现y1=x2-(a/b)*x2 
} 
int main(){
    cin>>n;
    rep(i,1,n) cin>>m[i]>>c[i];
    ll nowm = m[1],nowc = c[1];
    bool flag = 1;
    rep(i,2,n){
        if((c[i]-nowc)%gcd(nowm,m[i])){//不能被gcd整除，无解
            flag = 0;break;
        }
        ll p1,p2,gcdd;
        Exgcd(nowm,m[i],gcdd,p1,p2);
        ll bs = (c[i]-nowc)/gcdd;//算倍数,之后乘上去
        ll prem = nowm;
        nowm = lcm(m[i],nowm);//合并后模数为lcm
        nowc = (((bs%nowm)*p1%nowm)*prem)%nowm+nowc;//算合并后余数
        //bs*p1*prem+nowc;
        nowc = ((nowc%nowm)+nowm)%nowm;
    }
    if(!flag) cout<<-1<<endl;
    else cout<<nowc<<endl;
}