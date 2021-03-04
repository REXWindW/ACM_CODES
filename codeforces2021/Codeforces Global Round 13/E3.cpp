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
const int MAXN = 114514*10;
int fb[35];
int ifb[MAXN];
set<int> e[MAXN];
vector<int> points;
int n;
int siz[MAXN];
int fa[MAXN];
void init(){
    fb[0]=fb[1]=1;
    ifb[1]=1;
    rep(i,2,27){
        fb[i]=fb[i-1]+fb[i-2];
        ifb[fb[i]]=i;
    }
}
void dfs(int now,int prev){
    siz[now] = 1;
    points.push_back(now);
    for(auto v:e[now]){
        if(v==prev) continue;
        dfs(v,now);
        fa[v]=now;
        siz[now]+=siz[v];
    }
}
bool deal(int now,int nn){
    if(n<=3) return 1;//三个点往下的情况肯定可以
    //cout<<n<<":"<<xb<<":"<<fb[xb]<<endl;
    if(ifb[n]==0) return 0;
    points.clear();
    int tar = fb[ifb[nn]-1];
    dfs(now,0);//第二个数字不重要
    for(auto x:points){
        if(siz[x]==tar||nn-siz[x]==tar){
            e[x].erase(fa[x]);
            e[fa[x]].erase(x);
            return deal(x,siz[x])&&deal(fa[x],nn-siz[x]);
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