#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 2e5+5;
int n;
int a[MAXN];
int vis[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)
        vis[i] = 0;
    int hc;
    rep(i,1,n){
        cin>>hc;
        if(vis[hc]!=0) vis[hc]=-1;
        else vis[hc]=i;
    }
    int res = -1;
    rep(i,1,n){
        if(vis[i]>0){
            res = vis[i];break;
        }
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}