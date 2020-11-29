#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 256;
int vis[MAXN];
#define INF 0x3f3f3f3f
int n,m,k;
int d[MAXN][MAXN]={0};
int minn,minp;
int tp[MAXN];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        d[i][i] = 0;
        rep(j,0,n){
            d[i][j] = INF;
        }
    }
    int u,v;
    while(m--){
        cin>>u>>v;
        cin>>d[u][v];
        d[v][u] = d[u][v];//not sure
    }
    minn = INF;minp = -1;
    cin>>k;
    int hc;
    int fanganshu = 0;
    rep(i,1,k){
        cin>>hc;
        rep(i,1,hc){
            cin>>tp[i];
        }
        if(hc<n) continue;
        rep(i,1,n) vis[i] = 0;
        ll res = 0;
        int now = 0;
        rep(i,1,hc){
            res+=d[now][tp[i]];
            now = tp[i];
            vis[now]++;
        }
        res+=d[now][0];
        bool flag = 1;
        rep(i,1,n){
            if(vis[i]!=1) flag = 0;
        }
        if(res>=INF) continue;//走了没有的路
        //cout<<flag<<' '<<res<<endl;
        if(flag){
            fanganshu++;
            if(minn>res){
                minn = res;
                minp = i;
            }
        }
    }
    cout<<fanganshu<<endl;
    cout<<minp<<' '<<minn<<endl;
}
int main(){
    solve();
}