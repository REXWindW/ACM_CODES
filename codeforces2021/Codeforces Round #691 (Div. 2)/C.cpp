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
int n,m;
ll a[MAXN],b[MAXN];

void solve(){
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    n = unique(a+1,a+1+n)-a-1;
    if(n<=2){
        rep(j,1,m){
            cin>>b[j];
            if(n==1) cout<<a[1]+b[j]<<' ';
            else cout<<gcd(a[1]+b[j],a[2]+b[j])<<' ';
        }
        cout<<endl;
        return;
    }
    ll gcdd = gcd(a[3]-a[2],a[2]-a[1]);//后面的gcd一定小于d的gcd
    rep(i,4,n)
        gcdd = gcd(gcdd,a[i]-a[i-1]);
    rep(j,1,m){
        cin>>b[j];
        cout<<gcd(gcdd,a[1]+b[j])<<' ';
    }
    cout<<endl;
}

int main(){
    solve();
}