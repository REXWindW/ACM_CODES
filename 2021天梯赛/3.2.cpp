#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define ll long long
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 114514;
int k[114];
int a[114][11451];
bool vis[114];
int n,m;
int d[MAXN];//断口高度
int res[114];//最多114个纸条
bool jieshu = 0;
void dfs(int zt,int now){
    //cout<<"zt"<<zt<<"now"<<now<<endl;
    if(now==n+1){
        rep(i,1,zt){
            cout<<res[i];
            if(i!=zt) cout<<' ';
            //system("pause");
        }
        jieshu = 1;
        return;
    }
    rep(i,1,n){
        if(vis[i]) continue;
        if(now+k[i]>n+1) continue;//放不下了
        bool flag = 1;
        rep(j,0,k[i]-1){
            if(a[i][j]!=d[now+j]){flag=0;break;}
        }
        if(!flag) continue;
        vis[i] = 1;
        res[zt+1] = i;
        dfs(zt+1,now+k[i]);
        if(jieshu) return;
        vis[i] = 0;
    }
}
void solve(){
    cin>>n;
    rep(i,1,n) cin>>d[i];
    cin>>m;
    rep(i,1,m){
        cin>>k[i];
        rep(j,0,k[i]-1) cin>>a[i][j];
    }
    //cout<<"?"<<endl;
    dfs(0,1);
}
int main(){
    solve();
}