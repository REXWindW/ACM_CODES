#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 3*114514;
const ll LINF = 1ll<<62;
int n,m,k;
ll a[MAXN];
ll res = 0;
ll b[13];//模m为i上后缀和的最大值
void solve(){
    cin>>n>>m>>k;
    rep(i,0,m-1) b[i] = -LINF;
    rep(i,0,n-1) cin>>a[i];
    rep(i,0,n-1){
        rep(j,0,m-1) b[j] += a[i];
        b[i%m]-=k;
        b[i%m] = max(a[i]-k,b[i%m]);
        rep(j,0,m-1)res = max(res,b[j]);
        //cout<<"res"<<i<<':'<<res<<endl;
    }
    cout<<res<<endl;
}

int main(){
    solve();
}