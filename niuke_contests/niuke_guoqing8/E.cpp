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
const int MAXN = 66;
int n,k;

int p[MAXN];
int a[MAXN][MAXN];
int main(){
    cin>>n>>k;
    int pmax = 0;
    rep(i,0,n-1){
        cin>>p[i];
        pmax = max(p[i],pmax);
        rep(j,1,20) a[i][j] = 50;//填满
        rep(j,0,p[i]-1)cin>>a[i][j];
    }
    ll sum = 0;
    int cnt = 0;
    rep(i,0,pmax*n){
        if(cnt>=k) break;
        int now = a[i%n][i/n];
        if(now<sum){
            continue;
        }
        else{sum+=now;cnt++;}
    }
    if(cnt<k) sum += (k-cnt)*50;
    cout<<sum<<endl;
}