#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
//#define INF 0x7fffffff
const int med = 101;
const int MAXN = 1e5+5;
int n,q;
int z;
int f[MAXN],k[MAXN];
int vis[MAXN][102];
int mem[MAXN][102] = {0};//第几个到1的结果
int ppow[105][105];
inline void init(){//预处理幂,10000复杂度
    rep(i,1,100){
        ppow[i][0] = 1;
        rep(j,1,100){
            ppow[i][j] = ppow[i][j-1]*i%med;
        }
    }
}
inline int qpow(int di,int mi){
    return ppow[di][mi];
}
int dfs(int nr,int x){
    //cout<<"nr"<<nr<<endl;
    int nxt;
    if(nr == 0) return x;
    if(vis[nr][x]==z) return mem[nr][x];
    //cout<<x<<' ';
    if(f[nr]==1) nxt = (x+k[nr])%med;
    else if(f[nr]==2) nxt = (x*k[nr])%med;
    else nxt = qpow(x,k[nr]);//f=3;
    //cout<<nxt<<endl;
    vis[nr][x] = z;
    return mem[nr][x] = dfs(nr-1,nxt);
}
void solve(){
    scanf("%d%d",&n,&q);
    rep(i,1,n){
        scanf("%d%d",&f[i],&k[i]);
    }
    int ri,xi;
    rep(i,1,q){
        scanf("%d%d",&ri,&xi);
        printf("%d\n",dfs(ri,xi%med));
    }
}
int main(){
    init();
    int t;
    cin>>t;
    for(z=1;z<=t;z++) solve();
}