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

int n,m;
const int MAXN = 114514*3;
const int M = 15000000;
int prime[4000];
int a[MAXN];
int cntprim=0;
bool visit[4000];
map<int,int> mp;
void Prime(){
    for(int i=2;i*i<=M;i++){
        if(!visit[i]){
            prime[++cntprim]=i;//纪录素数， 这个prime[0] 相当于 cnt，用来计数
        }
        for(int j=1;j<=cntprim&&i*i*prime[j]*prime[j]<=M; j++) {
            visit[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

void solve(){
    cin>>n;
    int x;
    cin>>a[1];
    int gcdd = a[1];
    rep(i,2,n){
        cin>>a[i];
        gcdd = gcd(gcdd,a[i]);
    }
    int maxx = 0;
    rep(i,1,n){
        x = a[i]/gcdd;
        rep(i,1,cntprim){
            if(prime[i]>x) break;
            if(x%prime[i]==0){
                mp[prime[i]]++;
                maxx = max(maxx,mp[prime[i]]);
            }
            while(x%prime[i]==0) x/=prime[i];
        }
        if(x!=1){
            mp[x]++;
            maxx = max(maxx,mp[x]);
        }
    }
    if(maxx==0) cout<<-1<<endl;
    else cout<<n-maxx<<endl;
}

int main(){
    Prime();
    solve();
}