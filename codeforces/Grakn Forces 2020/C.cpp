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
const int MAXN = 1e5+5;
int a[MAXN];
double ts[MAXN],tn[MAXN];// 记录正着反着到达每个点的时间
int n,len;
void solve(){
	scanf("%d%d",&n,&len);
    rep(i,1,n) cin>>a[i];// 保证输入升序
    int v = 1;//速度
    double t = 0;
    a[0] = 0;a[n+1] = len;
    ts[0] = tn[n+1] = 0;
    rep(i,1,n){
        t += (double)(a[i]-a[i-1])/v;
        ts[i] = t;
        v++;
    }
    v=1,t=0;
    repb(i,n,1){
        t += (double)(a[i+1]-a[i])/v;
        tn[i] = t;
        v++;
    }
    int mid,l = 0,r = n+1;
    while(l<r){//找第一个正向会后到的点 ts>tn的
        mid = (l+r)>>1;
        if(ts[mid]<=tn[mid]) l = mid+1;
        else r = mid;
    }
    double dist = a[l]-a[l-1];
    double res = max(ts[l-1],tn[l]);
    int vs = l-1+1,vn = n+1-l+1;
    if(ts[l-1]>tn[l]){
        swap(vs,vn);
    }
    dist -= vs*fabs(ts[l-1]-tn[l]);//vs先到多走一段
    res+=(double)dist/(vs+vn);
    printf("%llf\n",res);
}
int main(){
	int z;
	cin>>z;
	while(z--) solve();
}