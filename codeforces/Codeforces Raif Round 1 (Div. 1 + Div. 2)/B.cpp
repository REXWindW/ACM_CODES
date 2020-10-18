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

string fx;
const int MAXN = 1e6+5;
bool ok[MAXN];
bool up[MAXN],down[MAXN];
int n;
inline int mo(int x){
    return (x+n)%n;
}
void solve(){
	cin>>n;
    cin>>fx;
    rep(i,0,n-1){
        ok[i]=0;
        if(fx[i]=='-') up[i] = down[i] = 1;
        else if(fx[i]=='>') up[i] = 1,down[i] = 0;
        else down[i] = 1,up[i] = 0;
    }
    bool flagu=1,flagd=1;
    rep(i,0,n-1){
        if(!up[i]) flagu = 0;
        if(!down[i]) flagd = 0;
        if(flagu==0&&flagd==0) break;
    }
    if(flagu||flagd){
        cout<<n<<endl;
        return;
    }
    ll cnt = 0;
    rep(i,0,n-1){
        if(up[(mo(i-1))]&&down[mo(i-1)]) ok[i] = 1;
        else if(up[i]&&down[i]) ok[i] = 1;
        cnt+=ok[i];
    }
    cout<<cnt<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}