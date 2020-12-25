#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n,m;
const int MAXN = 123;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int sx,sy;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int res;
bool OK(int x,int y){
    return x&&y&&x<=n&&y<=m;
}
void dfs2(int x,int y){
    int dx,dy;
    a[x][y]='#';
    rep(i,0,3){
        dx = x+dir[i][0];dy = y+dir[i][1];
        if(OK(dx,dy)&&a[dx][dy]=='@'&&!vis[dx][dy]&&a[dx][dy]!='X'){
            dfs2(dx,dy);
        }
    }
}
void dfs1(int x,int y){
    vis[x][y]=1;
    int dx,dy;
    if(a[x][y]=='@'){
        res++;
        dfs2(x,y);
    }
    rep(i,0,3){
        dx = x+dir[i][0];dy = y+dir[i][1];
        if(OK(dx,dy)&&!vis[dx][dy]&&a[dx][dy]!='X'){
            dfs1(dx,dy);
        }
    }
}
void solve(){
    getchar();
    res = 0;
    rep(i,1,n){
        rep(j,1,m){
            vis[i][j]=0;
            cin>>a[i][j];
            if(a[i][j]=='S'){
                sx = i;sy = j;
            }
        }
        getchar();
    }
    dfs1(sx,sy);
    cout<<res<<endl;
}
int main(){
    //freopen("G_in.txt","r",stdin);
    while(cin>>n>>m&&n&&m) solve();
}