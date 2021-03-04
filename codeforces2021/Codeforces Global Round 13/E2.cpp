#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514*4;
int fb[35];
set<int> e[MAXN];
vector<int> points;
int n;
int siz[MAXN];
int fa[MAXN];
int getfb(int x){//确定fb数组中的下标
    int px = lower_bound(fb+1,fb+1+31,x)-fb;
    if(fb[px]==x) return px;
    return -1;
}
void init(){
    fb[0]=fb[1]=1;
    rep(i,2,31) fb[i]=fb[i-1]+fb[i-2];
}
void dfs(int now,int prev){
    siz[now] = 1;
    points.push_back(now);
    for(auto v:e[now]){
        if(v==prev) continue;
        fa[v]=now;
        dfs(v,now);
        siz[now]+=siz[v];
    }
}
bool deal(int now,int n){
    if(n<=3) return 1;//三个点往下的情况肯定可以
    int xb = getfb(n);
    //cout<<n<<":"<<xb<<":"<<fb[xb]<<endl;
    if(xb==-1) return 0;
    points.clear();
    dfs(now,-1);//第二个数字不重要
    for(auto x:points){
        if(siz[x]==fb[xb-1]||siz[x]==fb[xb-2]){
            e[x].erase(fa[x]);
            e[fa[x]].erase(x);
            return deal(x,siz[x])&&deal(fa[x],n-siz[x]);
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].insert(v);
        e[v].insert(u);
    }
    if(deal(1,n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    init();
    solve();
}