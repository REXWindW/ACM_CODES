#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n;
const int MAXN = 114514;
vector<int> e[MAXN];
int maxx = 0;
int rt;
int fa[MAXN];
int res[MAXN];
int nw[MAXN];
void dfs(int now,int stp){
    //cout<<"now"<<now<<"stp"<<stp<<"siz"<<e[now].size()<<endl;
    nw[stp] = now;
    if(e[now].size()==0){//leaf
        if(stp>maxx){
            maxx = stp;
            rep(i,1,stp)res[i]=nw[i];
        }
        return;
    }
    for(auto v:e[now]){
        dfs(v,stp+1);
    }
}
void solve(){
    cin>>n;
    int hc,tmp;
    rep(i,0,n-1) fa[i] = i;
    rep(i,0,n-1){
        cin>>tmp;
        rep(j,1,tmp){
            cin>>hc;
            e[i].push_back(hc);
            fa[hc] = i;
        }
        sort(e[i].begin(),e[i].end());//输出最小序列
    }
    rep(i,0,n-1)
       if(fa[i]==i){rt=i;break;}
    dfs(rt,1);
    cout<<maxx<<endl;
    rep(i,1,maxx){
        cout<<res[i];
        if(i!=maxx) cout<<' ';
    }
    cout<<endl;
}
int main(){
    solve();
}