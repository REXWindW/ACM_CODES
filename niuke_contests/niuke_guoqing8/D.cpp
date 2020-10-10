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
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff

const int MAXN = 37;
int dp[MAXN][MAXN][MAXN][MAXN][MAXN];//四维背包
bool path[MAXN][MAXN][MAXN][MAXN][MAXN];
//p a c m
int g[MAXN];//每个队伍的价值
int P,A,C,M;//空间大小
int p[MAXN],a[MAXN],c[MAXN],m[MAXN];
int n;
int main(){
    cin>>n;
    memset(dp,0,sizeof(dp));
    memset(path,0,sizeof(path));
    rep(i,1,n) cin>>p[i]>>a[i]>>c[i]>>m[i]>>g[i];
    cin>>P>>A>>C>>M;
    rep(i,1,n){//循环队伍
        rep(ip,0,P){
            rep(ia,0,A){
                rep(ic,0,C){
                    rep(im,0,M){
                        if(ip>=p[i]&&ia>=a[i]&&ic>=c[i]&&im>=m[i]){//可以放得下
                            if(dp[i-1][ip][ia][ic][im]<dp[i-1][ip-p[i]][ia-a[i]][ic-c[i]][im-m[i]]+g[i]){
                                dp[i][ip][ia][ic][im]=dp[i-1][ip-p[i]][ia-a[i]][ic-c[i]][im-m[i]]+g[i];
                                path[i][ip][ia][ic][im]=1;
                            } 
                            else dp[i][ip][ia][ic][im]=dp[i-1][ip][ia][ic][im];
                        }
                    }
                }
            }
        }
    }
    //输出路径
    int np=P,na=A,nc=C,nm=M;
    vector<int>res;
    repb(i,n,1){
        if(path[i][np][na][nc][nm]){
            res.push_back(i);
            np-=p[i];na-=a[i];
            nc-=c[i];nm-=m[i];
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    if(res.size()){
        rep(i,0,res.size()-1){
            cout<<res[i]-1;
            if(i!=res.size()-1) cout<<' ';
        }
        cout<<endl;
    }
}