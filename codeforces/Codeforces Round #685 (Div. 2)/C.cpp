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
const int MAXN = 3e6+5;
//#define INF 0x7fffffff
string a,b;
inline int idx(char c){return c-'a';}
int n,k;
int cnta[26];
int cntb[26];
void solve(){
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    cin>>n>>k;
    cin>>a>>b;
    cout<<"read finished"<<endl;
    rep(i,0,n-1){
        cnta[idx(a[i])]++;
        cntb[idx(b[i])]++;
    }
    bool flag = 1;
    int pa=0,pb=0;
    while(pa<=25&&pb<=25){
        cout<<"pab"<<pa<<' '<<pb<<endl;
        while(cnta[pa]==0) pa++;
        while(cntb[pb]==0) pb++;
        if(pa>pb){
            flag = 0;
            break;
        }
        int d = min(cnta[pa],cntb[pb]);
        if(pa==pb){
            cnta[pa]-=d,cntb[pb]-=d;
            continue;
        }
        if(cnta[pa]<k){
            flag = 0;
            break;
        }
        cnta[pa+1]+=k;
        cntb[pa]-=k;
    }
    cout<<"while finished"<<endl;
    if(!flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}