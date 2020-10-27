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
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 1024;
int ma[MAXN][MAXN];
int n,m,a,b;
int tree[MAXN][MAXN];
//二维树状数组区间修改单点查询
inline bool OK(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m;
}
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int y,int v){
    while(x<=n){
        int ty = y;
        while(ty<=m){
            tree[x][ty]+=v;
            ty+=lowbit(ty);
        }
        x+=lowbit(x);
    }
}
inline void real_add(int x1,int y1,int x2,int y2,int v){
    add(x1,y1,v);
    add(x1,y2+1,-v);
    add(x2+1,y1,-v);
    add(x2+1,y2+1,v);
}
inline int ask(int x,int y){
    int res = 0;
    while(x){
        int ty = y;
        while(ty){
            res+=tree[x][ty];
            ty-=lowbit(ty);
        }
        x-=lowbit(x);
    }
    return res;
}
void solve(){
    cin>>n>>m>>a>>b;
    rep(i,1,n){
        rep(j,1,m){
            cin>>ma[i][j];
            tree[i][j] = 0;
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            int dd = ma[i][j]-ask(i,j);
            if(dd<0){cout<<"QAQ"<<endl;return;}
            if(dd){
                if(!OK(i+a-1,j+b-1)){cout<<"QAQ"<<endl;return;}
                real_add(i,j,i+a-1,j+b-1,dd);
            }
        }
    }
    cout<<"^_^"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}