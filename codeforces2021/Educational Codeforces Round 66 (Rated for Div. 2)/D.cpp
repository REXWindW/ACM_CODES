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
int n,k;
ll res;
const int MAXN = 114514*3;
ll a[MAXN],sum[MAXN];
void solve(){
    res = 0;
    cin>>n>>k;
    rep(i,1,n)
        cin>>a[i];
    sum[n+1]=0;
    repb(i,n,1){
        sum[i] = sum[i+1]+a[i];
    }
    res+=sum[1];
    sort(sum+2,sum+1+n,greater<ll>());
    rep(i,2,k){
        res+=sum[i];
    }
    cout<<res<<endl;
}

int main(){
    solve();
}