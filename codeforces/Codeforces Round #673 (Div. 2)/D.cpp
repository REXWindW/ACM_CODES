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
const int MAXN = 1e6+5;

ll a[MAXN],sum,pj;
ll x[MAXN],y[MAXN],z[MAXN];
int cnt,n;
inline void insert(int xx,int yy,int zz){
    x[cnt]=xx;y[cnt]=yy;z[cnt++]=zz;
}
void solve(){
    cin>>n;
    cnt=sum=0;
    rep(i,1,n){cin>>a[i];sum+=a[i];}
    if(sum%n){cout<<-1<<endl; return ;}
    pj = sum/n;
    rep(i,2,n){
        if(a[i]%i){
            insert(1,i,i-a[i]%i);
        }
        insert(i,1,(a[i]+i-1)/i);
    }
    rep(i,2,n) insert(1,i,pj);
    cout<<cnt<<endl;
    rep(i,0,cnt-1){
        cout<<x[i]<<' '<<y[i]<<' '<<z[i]<<endl;
    }
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}