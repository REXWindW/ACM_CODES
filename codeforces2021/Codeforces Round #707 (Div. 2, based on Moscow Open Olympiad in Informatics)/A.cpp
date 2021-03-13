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
const int MAXN = 1145141;
int a[MAXN],b[MAXN];
int tm[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i]>>b[i];
    }
    rep(i,1,n) cin>>tm[i];
    int now = 0;
    b[0] = 0;
    int t = 0;
    rep(i,1,n){
        now = t;
        now+=a[i]-b[i-1]+tm[i];
        t = max(b[i],now+(b[i]-a[i]+1)/2);
    }
    cout<<now<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}