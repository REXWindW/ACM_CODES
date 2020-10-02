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
const int MAXN = 666;
int n;
int a[MAXN][3];
int s[MAXN];
void solve(){
	cin>>n;
    rep(i,1,3)
        rep(j,1,n)cin>>a[j][i];
    a[0][1]=a[0][2]=a[0][3] = INF;
    s[0] = 1;
    rep(i,1,n-1){
        s[i] = 1;
        while(a[i][s[i]]==a[i-1][s[i-1]]) s[i]++;
    }
    s[n] = 1;
    while(a[n][s[n]]==a[n-1][s[n-1]]||a[n][s[n]]==a[1][s[1]]) s[n]++;
    rep(i,1,n) cout<<a[i][s[i]]<<' ';
    cout<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}