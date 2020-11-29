#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1e5+5;
struct Node{
    int ls,rs,data;
}t[MAXN];
int cntt=0;
int ept;
int maxdiv = 0;
int n;
void dfs(int u,int d){
    if(d==maxdiv){
        if(cntt<ept)cin>>t[u].data;
        //cout<<"cnt"<<cntt<<endl;
        cntt++;
        return;
    }
    t[u].ls = u*2;
    t[u].rs = u*2+1;
    dfs(t[u].ls,d+1);
    dfs(t[u].rs,d+1);
    cin>>t[u].data;//hou xv
}
void solve(){
    cin>>n;
    maxdiv = 0;
    int now = 1;
    int tot = 0;
    maxdiv = 0;
    while(tot<n){
        maxdiv++;
        tot+=now;
        now*=2;//cnt div
    }
    now/=2;
    ept = now-(tot-n);//last div number node
    //cout<<"maxdiv"<<maxdiv<<endl;
    dfs(1,1);//node,div
    rep(i,1,n){
        cout<<t[i].data;
        if(i!=n) cout<<' ';
    }
}
int main(){
    solve();
}