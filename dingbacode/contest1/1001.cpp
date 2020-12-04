#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
//#define INF 0x7fffffff
const int MAXN = 2e5+5;
int n,m;
ll maxk;
vector<ll>a[MAXN];
inline ll get(int x1,int y1,int x2,int y2){//快速取子矩阵和
    return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
}
void solve(){
    ll hc;
    read(n);read(m);read(maxk);
    rep(j,1,m) a[0].push_back(0);
    rep(i,1,n){
        a[i].push_back(0);
        rep(j,1,m){
            read(hc);
            hc = hc+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            a[i].push_back(hc);//矩阵前缀和
        }
    }
    ll res = 0;
    //对短的一轴n方枚举,另一轴滑窗
    if(n<=m){
        rep(i,1,n){
            rep(j,i,n){
                int px = 1;//滑窗另一端
                rep(k,1,m){
                    while(px<=k&&get(i,px,j,k)>maxk)px++;
                    res+=k-px+1;//统计
                }
            }
        }
    }
    else if(n>m){
        rep(i,1,m){
            rep(j,i,m){
                int px = 1;
                rep(k,1,n){
                    while(px<=k&&get(px,i,k,j)>maxk)px++;
                    res+=k-px+1;
                }
            }
        }
    }
    cout<<res<<endl;
    rep(i,0,n) a[i].clear();
}

int main(){
    int z;
    read(z);
    while(z--) solve();
}