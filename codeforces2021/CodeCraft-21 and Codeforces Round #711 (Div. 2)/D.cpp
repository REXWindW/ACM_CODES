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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 202;
const int MAXM = 5e6+5;
int t[MAXN],x[MAXN],y[MAXN];
int res[MAXM];//最早到达的时间
int n,m;

inline ll cl(ll x,ll y){//向上取整
    return (x*y+99999)/100000;
}

void dfs(ll now,int st){
    if(st==m+1) return;
    if(st>=res[now]) return;
    res[now] = st;//更新最早出现位置
    dfs(now,st+1);//不操作
    if(t[st]==1){//add
        rep(i,1,y[st]){
            now++;
            dfs(now,st+1);    
        }
    }
    else if(t[st]==2){//time
        rep(i,1,y[st]){
            now = cl(now,x[st]);
            dfs(now,st+1);
        }
    }
}

inline void solve(){
    cin>>n>>m;
    rep(i,1,m) res[i] = INF;
    rep(i,1,n) cin>>t[i]>>x[i]>>y[i];
    dfs(0,1);
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}