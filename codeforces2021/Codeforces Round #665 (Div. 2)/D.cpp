#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
vector<int> e[MAXN];
int n,m;
int siz[MAXN];//维护子树大小
int p[MAXN];
const ll med = 1e9+7;

void dfs(int now,int pre){
    siz[now] = 1;
    for(auto v:e[now]){
        if(v==pre) continue;
        dfs(v,now);
        siz[now]+=siz[v];//预处理size
    }
}

ll tl[MAXN];//记录该点往上的边的通路数,这个是可能很大的
vector<ll> vec;//通路算出来之后还要push进去的
void dfs2(int now,int pre){
    tl[now] = 0;
    if(pre!=-1){//根节点没有向上的边
        tl[now] = (ll)siz[now]*(siz[1]-siz[now]);
        vec.push_back(tl[now]);
        //cout<<"!"<<endl;
    }
    for(auto v:e[now]){
        if(v==pre) continue;
        //cout<<"!v"<<v<<endl;
        dfs2(v,now);
    }
}
void solve(){
    vec.clear();
    cin>>n;
    rep(i,1,n) e[i].clear();
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>m;
    rep(i,1,m) cin>>p[i];
    sort(p+1,p+1+m,greater<int>());
    dfs(1,-1);
    dfs2(1,-1);
    sort(vec.begin(),vec.end(),greater<ll>());
    //cout<<"vecsiz"<<vec.size()<<endl;
    //注意：1一定要尽可能小的
    ll res = 0;
    if(m>=n-1){//不需要1的情况
        ll tmp = 1;
        int px = 1;
        for(;px<=m-(n-2);px++) tmp = tmp*p[px]%med;//这些多出来的全部给最大的一条边
        res=(res + tmp*vec[0])%med;
        rep(i,1,n-2){
            res=(res + vec[i]*p[px])%med;
            px++;
        }
    }
    else{
        rep(i,0,n-2){
            if(i<m){//靠前的都可以分配质数
                res = (res+p[i+1]*vec[i])%med;
            }
            else res = (res+vec[i])%med;
        }
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}