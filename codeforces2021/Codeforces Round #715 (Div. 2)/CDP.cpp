#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 2020;
ll dp[MAXN][MAXN];
ll a[MAXN];
int n;
inline void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    rep(len,2,n){
        rep(l,1,n-len+1){
            int r = l+len-1;
            dp[l][l+len-1]=min(dp[l+1][r],dp[l][r-1])+a[r]-a[l];
        }
    }
    cout<<dp[1][n]<<endl;
}

int main(){solve();
}