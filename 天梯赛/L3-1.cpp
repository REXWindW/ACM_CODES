#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1486;
int d[MAXN];
int s,t;
vector<int> e[MAXN];
ll res[MAXN];//每个点的结果
int n,m;
void solve(){
    cin>>n>>m;
    int u,v;
    while(m--){
        cin>>u>>v;
        e[u].push_back(v);
        d[v]++;
    }
    cin>>s>>t;
    res[s] = 1;
    queue<int>q;
    rep(i,1,n){
        if(d[i]==0) q.push(i);
    }
    int now;
    int tot = 0;
    int cnt =0;
    while(!q.empty()){
        now = q.front();
        q.pop();
        tot++;
        if(e[now].size()==0){
            if(res[now]!=0) cnt++;//new
        }
        for(auto to:e[now]){
            d[to]--;
            res[to]+=res[now];
            if(d[to]==0) q.push(to);
        }
    }
    cout<<res[t]<<' ';
    if(cnt==1&&res[t]>0&&tot==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    solve();
}