#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
const ll INF = 1ll<<60;
const int MAXN = 114514;

int n;
ll d;
ll a[MAXN];

void solve(){
    cin>>n>>d;
    rep(i,1,n) cin>>a[i];
    a[0]=-INF;a[n+1]=INF;
    int cnt = 0;
    rep(i,1,n+1){
        if(a[i]-a[i-1]>=d*2) cnt++;
        if(i!=1&&i!=n+1&&a[i]-a[i-1]>d*2) cnt++;
    }
    cout<<cnt<<endl;
}

int main(){
    solve();
}