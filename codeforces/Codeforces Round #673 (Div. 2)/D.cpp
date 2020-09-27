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
const int MAXN = 1e4+5;
ll a[MAXN];
ll sum;
int n;
void solve(){
    cin>>n;
    sum = 0;
    rep(i,1,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n){cout<<-1<<endl;return;}
    ll pj = sum/n;
    rep(i,2,n){
        if(a[i]>=i){
            cout<<i<<' '<<1<<' '<<a[i]/i<<endl;
            a[1] += a[i]-(a[i]%i);
            a[i] = a[i]%i;
        }
    }
    rep(i,2,n){
        if(a[i]>pj){
            cout<<1<<' '<<i<<' '<<i-a[i]<<endl;
            cout<<i<<' '<<1<<' '<<1<<endl;
            a[1]+=a[i];a[i] = 0;
        }
        }
        rep(i,1,n){
            if(a[i]!=pj){
                cout<<1<<' '<<i<<' '<<pj-a[i]<<endl;
            }
        }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}