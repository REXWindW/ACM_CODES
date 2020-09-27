#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
int n,z;
const int MAXN = 3e5+5;
int a[MAXN],pre[MAXN],mad[MAXN],res[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n){cin>>a[i];pre[i]=0;mad[i]=0;}
    rep(i,1,n){
        mad[a[i]] = max(mad[a[i]],i-pre[a[i]]);
        pre[a[i]] = i;
    }
    rep(j,1,n) mad[j] = max(mad[j],n+1-pre[j]);//最后未处理的
    int px = n;
    for(int i=1;i<=n;i++){//枚举数字
        while(mad[i]<=px&&px>=1){
            res[px--]=i;
        }
    }
    rep(i,1,px) res[i] = -1;
    //cout<<"test mad"<<endl;
    //rep(i,1,n) cout<<mad[i]<<' ';
    //cout<<endl;
    rep(i,1,n) cout<<res[i]<<' ';
    cout<<endl;
}

int main(){
    cin>>z;
    while(z--) solve();
}