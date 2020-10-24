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
int n;
const int MAXN = 3e5+5;
int a[MAXN];
vector<pii> vec;
//对于每个上升区间，这一次的结尾比上一次的开头大,最后一个也当成是一个上升
void solve(){
    vec.clear();
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int st,ed;
    if(a[1]>a[2]) vec.push_back(mkp(1,1));
    rep(i,2,n){
        if(a[i]>a[i-1]){//开始上升序列
            st = i-1;
            while(i<=n&&a[i]>a[i-1]) i++;
            i--;
            ed = i;
            vec.push_back(mkp(st,ed));
        }
        else if(i==n){
            vec.push_back(mkp(i,i));
        }
    }
    int siz = vec.size();
    if(a[vec[siz-1].sd]>a[vec[0].ft]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}