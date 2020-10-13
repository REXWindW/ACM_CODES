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
typedef pair<ll,ll> pll; 
const ll LINF = 5e18;
const int MAXN = 2e5+5;

ll n,m,s,t,hs;
ll hand[MAXN];//1=R，0=M，-1=L 
vector<pll> e[MAXN];
bool vis[MAXN];
ll d[MAXN];//分左手右手去处理 

void add_edge(int u,int v,ll dis){
    if(hand[v]==0) swap(u,v);
    if(hand[u]==0){
        if(hand[v]==0){
            e[u].push_back(make_pair(dis,v));
            e[v].push_back(make_pair(dis,u));
            e[u+n].push_back(make_pair(dis,v+n));
            e[v+n].push_back(make_pair(dis,u+n));
        }
        else if(hand[v]==1){
            e[u].push_back(make_pair(dis+hs,v));
            e[v].push_back(make_pair(dis+hs,u));
            e[u+n].push_back(make_pair(dis,v));
            e[v].push_back(make_pair(dis,u+n));
        }
        else if(hand[v]==-1){
            e[u].push_back(make_pair(dis,v));
            e[v].push_back(make_pair(dis,u));
            e[u+n].push_back(make_pair(dis+hs,v));
            e[v].push_back(make_pair(dis+hs,u+n));
        }
        
    }
    else if(hand[u]==hand[v]){
        e[u].push_back(make_pair(dis,v));
        e[v].push_back(make_pair(dis,u));
    }
    else{
        e[u].push_back(make_pair(dis+hs,v));
        e[v].push_back(make_pair(dis+hs,u));
    }
}

void solve(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&t,&hs);
    char hc;
    getchar();
    rep(i,1,n){
        scanf("%c",&hc);
        if(hc=='L') hand[i] = -1;
        else if(hc=='R') hand[i] = 1;
        else{
            hand[i]=0;
            vis[i+n]=0;
            d[i+n]=LINF;
            e[i+n].clear();
        }
        //初始化 
        e[i].clear();
        d[i] = LINF;
        vis[i] = 0;
    }
    int u,v;
    ll dis;
    rep(i,1,m){
        scanf("%d%d%lld",&u,&v,&dis);
        add_edge(u,v,dis);
    }
    priority_queue<pll,vector<pll>,greater<pll> >q;
    d[s] = 0;
    q.push(make_pair(0,s));
    if(hand[s]==0){
        q.push(make_pair(0,n+s));
        d[s+n] = 0;
    }
    while(!q.empty()){
        int now=q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        int siz = e[now].size();
        for(int i=0;i<siz;i++){
            int v = e[now][i].second;
            if(d[v]>d[now]+e[now][i].first){
                d[v] = d[now]+e[now][i].first;
                q.push(make_pair(d[v],v));
            }
        }
    }
    ll res = d[t];
    if(hand[t]==0) res = min(res,d[t+n]);
    printf("%lld\n",res);
}

int main(){
    int z;
    scanf("%d",&z);
    while(z--) solve(); 
}
