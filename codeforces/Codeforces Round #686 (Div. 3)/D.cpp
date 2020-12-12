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

ll n;
typedef pair<ll,ll> pll;
vector<pll> a;//ft time sd num
void solve(){
    a.clear();
    cin>>n;
    ll sqr = sqrt(n);
    rep(i,2,sqr){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            a.push_back(mkp(cnt,i));
        }
    }
    if(n) a.push_back(mkp(1,n));
    sort(a.begin(),a.end(),greater<pll>());
    int siz = a.size();
    int m = a[0].ft;
    ll now = 1;
    int px = 0;
    cout<<m<<endl;
    repb(i,m,1){
        for(;px<siz&&a[px].ft==i;px++){
            now*=a[px].sd;
        }
        cout<<now<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}