#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n;
const int MAXN = 1145;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define ft first
#define sd second
#define mkp make_pair
vector<ppi> edges;
vector<ppi> nedges;
vector<int> e[MAXN];
vector<int> ne[MAXN];
int d[MAXN];
int dd[MAXN];
bool flag[MAXN];
bool vis[MAXN][MAXN];
bool inst[MAXN];
bool flagg;

int fd(int now,int pre){
    int siz = ne[now].size();
    int too;
    rep(i,0,siz-1){
        too = nedges[ne[now][i]].ft.sd;
        if(too==pre) continue;
        return fd(too,now);//递归找到
    }
    return now;//到达顶端的情况
}
int dfs(int now,int pre,int co,int frst){
    cout<<"check"<<now<<' '<<pre<<endl;
    if(vis[frst][now]&&frst!=now) return -1;
    vis[frst][now]=vis[now][frst]=1;
    if(co!=-INF&&(d[now]==1||d[now]>=3)){
        return now;//回传，构建边了！
    }
    int siz = e[now].size();
    ppi eg;
    int to,ret;
    rep(i,0,siz-1){
        eg = edges[e[now][i]];
        if(eg.ft.sd==pre) continue;
        if(co!=-INF&&eg.sd!=co){//颜色不匹配的情况
            flagg = 0;
            return -1;
        }
        to = eg.ft.sd;
        ret = dfs(to,now,eg.sd,frst);//下传颜色
        if(ret==-1) continue;//对面已经访问过了的情况
        if(co=-1){//是起始点的情况
            inst[now]=inst[ret] = 1;
            ne[now].push_back(nedges.size());
            nedges.push_back(mkp(mkp(now,ret),eg.sd));
            ne[now].push_back(nedges.size());
            nedges.push_back(mkp(mkp(ret,now),eg.sd));
            dd[now]++,dd[ret]++;
        }
    }
    return ret;
}

int dfs2(int now,int pre){
    if(dd[now]==1){
        return now;
    }
    int siz = ne[now].size();
    int too;
    rep(i,0,siz-1){
        too = nedges[ne[now][i]].ft.sd;
        if(too==pre) continue;
        if(nedges[ne[now][i]].sd%2){
            nedges[ne[now][i]].sd++;
            nedges[ne[now][i]^1].sd++;//都给+1
            return dfs2(too,now);   
        }
    }
    //到这儿说明没找到奇数边了，此图无解
    flagg = 0;
    return -1;
}

vector<ppi> res;
void solve(){
    flagg = 1;
    cin>>n;
    int u,v,co;
    rep(i,1,n-1){
        cin>>u>>v>>co;
        e[u].push_back(edges.size());
        edges.push_back(mkp(mkp(u,v),co));
        e[v].push_back(edges.size());
        edges.push_back(mkp(mkp(v,u),co));
        d[u]++;d[v]++;
    }
    rep(i,1,n){
        if(d[i]==1||d[i]>=3)
            flag[i] = 1;
    }
    rep(i,1,n){
        if(flag[i]){
            dfs(i,-1,-INF,i);
        }
    }
    if(!flagg){
        cout<<"NO"<<endl;//因为边无法合并而NO
        return;
    }
    rep(i,1,n){
        if(inst[i]){//访问一下这些新的点
            if(dd[i]==2){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    int siz = nedges.size();
    int ed;
    for(int i=0;i<siz;i++){
        u = nedges[i].ft.ft;
        v = nedges[i].ft.sd;
        co = nedges[i].sd;
        if(dd[u]!=1) continue;//只从u叶子开始
        if(co%2){//奇数的情况
            nedges[i].sd++;
            nedges[i^1].sd++;//给+1
            ed = dfs2(v,u);
            res.push_back(mkp(mkp(u,ed),1));//都给+1
        }
        if(!flagg){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<siz;i+=2){
        u = nedges[i].ft.ft;
        v = nedges[i].ft.sd;
        co = nedges[i].sd;
        if(dd[u]==1&&dd[v]==1){
            res.push_back(mkp(mkp(u,v),co));
            break;
        }
        if(dd[u]==1) swap(u,v);
        int sizz = e[u].size();
        int too;
        int c[4],cnt=0;
        rep(i,0,sizz-1){
            too = nedges[ne[u][i]].ft.sd;
            if(too!=v) c[++cnt]=fd(too,u);
            if(cnt==2) break;
        }
        c[3] = fd(v,u);
        res.push_back(mkp(mkp(c[1],c[3]),co/2));
        res.push_back(mkp(mkp(c[2],c[3]),co/2));
    }
    cout<<"YES"<<endl;
    siz = res.size();
    rep(i,0,siz-1){
        cout<<res[i].ft.ft<<' '<<res[i].ft.sd<<' '<<res[i].sd<<endl;
    }
}

int main(){
    solve();
}