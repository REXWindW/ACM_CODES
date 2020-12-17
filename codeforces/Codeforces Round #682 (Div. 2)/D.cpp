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
int n,hc,tot;
void solve(){
    cin>>n;
    tot = 0;
    rep(i,1,n){
        cin>>hc;
        tot^=hc;
    }
    if(n%2){
        cout<<"YES"<<endl;
        cout<<(n/2)*2-1<<endl;
        for(int i=1;i+2<=n;i+=2)
            cout<<i<<' '<<i+1<<' '<<i+2<<endl;
        for(int i=n-4;i>=1;i-=2)
            cout<<i<<' '<<i+1<<' '<<i+2<<endl;
        cout<<endl;
    }
    else if(tot==0){
        cout<<"YES"<<endl;
        cout<<((n-1)/2)*2-1<<endl;
        for(int i=1;i+2<=n-1;i+=2)
            cout<<i<<' '<<i+1<<' '<<i+2<<endl;
        for(int i=n-5;i>=1;i-=2)
            cout<<i<<' '<<i+1<<' '<<i+2<<endl;
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    solve();
}