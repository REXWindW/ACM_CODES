#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
#define int ll
int a[MAXN];
ll sum;
int n,k,m;
void solve(){
    sum = 0;
    scanf("%lld%lld%lld",&n,&k,&m);
    a[0] = 0;
    rep(i,1,n){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    sort(a+1,a+1+n);
    int tmp = min(m,n-1);
    ll ad;
    double res=0;
    rep(i,0,tmp){//枚举删掉哪些点
        sum-=a[i];
        ad = min(m-i,k*(n-i));
        res = max(res,(double)(sum+ad)/(n-i));
    }
    printf("%.10lf\n",res);
}

signed main(){
    solve();
}