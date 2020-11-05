#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
const int MAXN = 16666;
const int INF = 0x7fffffff;
ll w[MAXN];
int n;
ll res = -INF;
vector<int> e[MAXN];
void dfs(int x,int prev){
    for(auto v:e[x]){
        if(v==prev) continue;
        dfs(v,x);
        if(w[v]>0) w[x]+=w[v];
    }
    res = max(res,w[x]);
}
int main(){
    cin>>n;
    rep(i,1,n){
        cin>>w[i];
    }
    int u,v;
    rep(i,1,n-1){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,-1);
    cout<<res<<endl;
}