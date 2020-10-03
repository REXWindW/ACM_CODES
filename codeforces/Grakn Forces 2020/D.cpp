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
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 2020;
int n,m;
struct Node{
    int x,y;
};
int f[1000010]={0};
Node a[MAXN],b[MAXN];
int main(){
    cin>>n>>m;
    rep(i,1,n) cin>>a[i].x>>a[i].y;
    rep(i,1,m) cin>>b[i].x>>b[i].y;
    rep(i,1,n)
        rep(j,1,m)
            if(b[j].x>=a[i].x)
                f[b[j].x-a[i].x] = max(f[b[j].x-a[i].x],b[j].y-a[i].y+1);
                //f[x]记录往右走了x步之后至少需要向上走多少步才能脱离，但这里的f[x]并步完全准确
                //实际应该往上走的值应该是max{f[i],i>=x}
    int ans = INF;
    int max_back = 0;//记录当前i到末尾位置的f最大值
    repb(i,1000009,0){
        max_back = max(max_back,f[i]);
        ans = min(ans,max_back+i);
    }
    cout<<ans<<endl;
}