#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const int MAXN = 1e5+10;
int fa[MAXN];
bool vis[MAXN];

int find(int x){//路径压缩
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool flag;
void merge(int x,int y){//y当x儿子
    int fx = find(x);
    int fy = find(y);
    if(fx==fy) flag = 0;
    if(fy!=y) flag = 0;
    fa[y] = fx;
}
void init(){
    flag = 1;
    memset(vis,0,sizeof(vis));
}
int main(){
    int z = 0;
    while(1){
        z++;
        int x,y;
        init();
        int maxx=0;
        while(cin>>x>>y&&x!=0){
            //cout<<x<<' '<<y<<endl;
            if(x<0) return 0;
            if(vis[x]==0) fa[x]=x;
            if(vis[y]==0) fa[y]=y;
            vis[x] = vis[y] = 1;
            merge(x,y);
            maxx = max(maxx,max(x,y));
        }
        int cnt = 0;
        rep(i,1,maxx){
            if(vis[i])
                if(fa[i]==i) cnt++;
            if(cnt>1){
                flag = 0;break;
            }
        }
        if(flag)
            cout<<"Case "<<z<<" is a tree."<<endl;
        else
            cout<<"Case "<<z<<" is not a tree."<<endl;
    }
}