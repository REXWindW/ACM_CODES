#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int MAXN = 5050;
const int MAXM = 2e5+5;
struct Edge{
    int u,v,k;
    friend bool operator < (Edge a,Edge b){
        return a.k<b.k;
    }
}edges[MAXM];
int fa[MAXN];
int rankk[MAXN];//树高优化并查集
int find(int x){
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int a,int b){
    a = find(a);b = find(b);
    if(a==b) return;
    if(rankk[a]>rankk[b]) fa[b] = a;
    else{
        fa[a] = b;
        if(rankk[a]==rankk[b])rankk[b]++; 
    }
}
int n,m;
int main(){
    cin>>n>>m;
    rep(i,1,m) cin>>edges[i].u>>edges[i].v>>edges[i].k;
    rep(i,1,n) fa[i] = i,rankk[i] = 0;
    sort(edges+1,edges+1+m);
    ll res=0;
    rep(i,1,m){
        if(find(edges[i].u)!=find(edges[i].v)){//检查两点是否在同一集合内
            res+=edges[i].k;
            merge(edges[i].u,edges[i].v);
        }
    }
    bool flag = 1;
    rep(i,2,n){
        if(find(n)!=find(n-1)) {flag = 0;break;}
    }
    if(!flag) cout<<"orz"<<endl;
    else cout<<res<<endl;
}
//P3366 【模板】最小生成树 https://www.luogu.com.cn/problem/P3366