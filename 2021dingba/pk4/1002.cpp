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
//tree dp
const int MAXN = 114514;
vector<pii> e[MAXN];
int f[MAXN];//积分数量
ll d[MAXN];
int n,pj;
ll res;
void dfs(int now,int prev){
    for(auto v:e[now]){
        if(v.sd==prev) continue;
        dfs(v.sd,now);
        res+=v.ft*abs(d[v.sd]);//往下/往上运的花费
        d[now]+=d[v.sd];
    }
}

void solve(){
    cin>>n;
    ll tot = 0;
    rep(i,1,n) cin>>f[i],tot+=f[i];
    pj = tot/n;//最终目标值
    rep(i,1,n) d[i] = pj-f[i];
    int u,v,w;
    rep(i,1,n-1){
        cin>>u>>v>>w;
        e[u].push_back(mkp(w,v));
        e[v].push_back(mkp(w,u));
    }
    dfs(1,-1);
    cout<<res<<endl;
}

int main(){
    solve();
}