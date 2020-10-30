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
const int MAXN = 2e5+5;
int h,n;
int res;
int a[MAXN];//每个台阶高度
void solve(){
    res = 0;
    cin>>h>>n;
    a[0]=0;
    repb(i,n,1) cin>>a[i];
    int now = h;//当前位置
    int px = n-1;//px往下降落,确定h处有一台阶
    int cnt = 1;//把h台阶加进去
    while(px>0){
        while(px>=0&&a[px]==now-1){
            px--;now--;cnt++;
        }
        if(px==-1) break;
        if(cnt%2==0){
            res++;
        }
        now = a[px]+1;
        cnt = 1;
    }
    cout<<res<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}