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

#define int ll

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
const int MAXN = 2e5+5;
vector<int> e[MAXN];
int n;
int fa[MAXN];//记录父亲
int di[MAXN];//记录深度
bool vis[MAXN];
vector<int> cir;//环中元素
bool incir[MAXN];//在不在环里
ll res;
inline void huan(int a,int b){//on找lca没事
    while(a!=b){
        //cout<<"lca"<<a<<' '<<b<<endl;
        if(di[a]<di[b]) swap(a,b);//保证a更深
        cir.push_back(a);
        a = fa[a];
    }
    cir.push_back(a);//lca也要push进去
}
bool flag;
int dfs2(int now,int pre,bool opt){//opt表示这个点是不是圈里的，如果是要检查set
    int ret = 1;
    for(auto v:e[now]){
        //cout<<now<<"to"<<v<<endl;
        if(v==pre) continue;
        if(opt&&!incir[v]){
            ret+=dfs2(v,now,0);
        }
        else if(!opt){
            ret+=dfs2(v,now,0);
        }
    }
    return ret;
}
void dfs(int now,int pre){
    //cout<<"now"<<now<<endl;
    vis[now] = 1;
    for(auto v:e[now]){
        if(v==pre) continue;
        if(vis[v]){
            huan(now,v);
            flag = 0;
            return;
        }
        di[v] = di[now]+1;
        fa[v] = now;//处理父亲
        dfs(v,now);
        if(flag==0) return; 
    }
}
void solve(){
    res = 0;
    cin>>n;
    int u,v;
    rep(i,1,n){
        e[i].clear();
    }
    cir.clear();
    rep(i,1,n){
        vis[i] = 0;
        incir[i] = 0;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int rt = 1;
    di[rt] = 1;//深度
    fa[rt] = rt;
    flag = 1;
    dfs(rt,-1);//dfs找环
    /*
    cout<<"now find huan siz"<<cir.size()<<endl;
    int sizz = cir.size();
    rep(i,0,sizz-1) cout<<cir[i]<<' ';
    cout<<endl;
    */
    int siz = cir.size();
    rep(i,0,siz-1) incir[cir[i]] = 1;//标记在圈内
    res = siz*(siz-1);//环自己之间的路径数量
    //找到环之后缩点并处理以环为根子树的节点数
    ll now,tot=0;//
    rep(i,0,siz-1){
        now = dfs2(cir[i],-1,1);
        //cout<<cir[i]<<"find"<<now<<endl;
        if(now==1) continue;
        now--;//不包含环上的这个点
        res+= now*(now-1)/2;//子树自己之间的
        res+= now;//这些点到当前i节点
        res+= now*(siz-1)*2;//子树到环里的其他元素有两条路
        res+= now*tot*2;//后加入的子树和先加入的子树之间也有两条
        tot+= now;
    }
    cout<<res<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}