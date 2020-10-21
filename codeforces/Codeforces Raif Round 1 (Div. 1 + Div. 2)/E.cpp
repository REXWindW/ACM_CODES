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
//#define INF 0x7fffffff
int n,k;
inline ll cal(int x,int d){//计算数字x切d刀后需要多少费用
    int dg = x/d;
    if(dg==0) return INF;
    int ys = x%d;
    return 1ll*ys*(dg+1)*(dg+1) + 1ll*(d-ys)*dg*dg;
}
struct cmp{
    bool operator () (pii a,pii b){
        return cal(a.ft,a.sd)-cal(a.ft,a.sd+1)<cal(b.ft,b.sd)-cal(b.ft,b.sd+1);
    }
};
priority_queue<pii,vector<pii>,cmp> q;
int main(){
    cin>>n>>k;
    int hc;
    rep(i,1,n){
        cin>>hc;
        q.push(mkp(hc,1));
    }
    pii now;
    rep(i,n,k-1){
        now = q.top();
        q.pop();
        now.sd++;
        q.push(now);
    }
    ll res = 0;
    while(!q.empty()){
        now = q.top();
        q.pop();
        res += cal(now.ft,now.sd);
    }
    cout<<res<<endl;
}