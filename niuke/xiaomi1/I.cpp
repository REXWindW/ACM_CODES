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

const int MAXN = 1024;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int n,m;
int cnt;
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};//wasd back sdwa
bool OK(int x,int y){
    return x>0 && y>0 && x<=n && y<=m;
}
void dfs(int x,int y){
    //cout<<x<<' '<<y<<endl;
    if(vis[x][y]) return;
    vis[x][y] = 1;
    cnt++;
    rep(i,0,3){
        int dx = x+dir[i][0];
        int dy = y+dir[i][1];
        if(OK(dx,dy)&&!vis[dx][dy]&&a[dx][dy]==i) dfs(dx,dy);
    }
}

void solve(){
    cnt = 0;
	cin>>n>>m;
    char hc;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            if(hc=='W') a[i][j]=0;
            else if(hc=='A') a[i][j]=1;
            else if(hc=='S') a[i][j]=2;
            else if(hc=='D') a[i][j]=3;
            vis[i][j] = 0;
        }
    }
    //上侧
    rep(j,1,m){
        if(a[1][j]!=0) continue;
        //cout<<"W"<<1<<j<<endl;
        dfs(1,j);
    }
    //下侧
    rep(j,1,m){
        if(a[n][j]!=2) continue;
        //cout<<"S"<<n<<j<<endl;
        dfs(n,j);
    }
    //左侧
    rep(i,1,n){
        if(a[i][1]!=1) continue;
        //cout<<"A"<<i<<1<<endl;;
        dfs(i,1);
    }
    //右侧
    rep(i,1,n){
        if(a[i][m]!=3) continue;
        //cout<<"D"<<i<<m<<endl;
        dfs(i,m);
    }
    /*
    rep(i,1,n){
        rep(j,1,m){
            cout<<vis[i][j];
        }
        cout<<endl;
    }
    */
    cout<<cnt<<endl;
}

int main(){
	solve();
}