#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int n;
const int med = 998244353;
ll dp,jc,jj;
void solve(){
    cin>>n;
    dp = 0;
    jc = 1;
    jj = 1;
    rep(i,2,n){
        dp= i*dp%med + jc*jj%med;
        //cout<<i<<':'<<dp<<' '<<jj<<' '<<jc<<endl;
        dp%=med;
        jc=jc*i%med;//更新jc
        jj=(jj+i)%med;
    }
    cout<<dp<<endl;
}

int main(){
    solve();
}