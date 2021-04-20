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
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int a[MAXN];
int sum[MAXN];
int n,q,l,r;

void solve(){
    cin>>n;
    sum[0] = 0;
    rep(i,1,n){
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1])/10<<endl;
    }
}

int main(){
    solve();
}