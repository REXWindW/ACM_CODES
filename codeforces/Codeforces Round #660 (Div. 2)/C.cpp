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
const int MAXN = 1e5+5;
int h[MAXN],p[MAXN];
vector<int> e[MAXN];
int n,m; 
int pass[MAXN];
bool flag;
void dfs1(int x,int prev){
    pass[x] = p[x];
    for(auto v:e[x]){
        if(v==prev) continue;
        pass[x] += pass[v];
    }
}
void dfs2(int x,int prev){
    for(auto v:e[x]){
        if(v==prev) continue;
        
    }
}

void solve(){
    flag = 1;//记录是否正常
	cin>>n>>m;
    rep(i,1,n) cin>>p[i];
    rep(i,1,n){
        e[i].clear();
        cin>>h[i];
    }
    int u,v;
    rep(i,1,n-1){//加边
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    //树形dp

}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}