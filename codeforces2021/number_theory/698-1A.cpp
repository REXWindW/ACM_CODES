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
const int MAXN = 114514*2;
ll a[MAXN];
int n;ll k;
void solve(){
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    ll gcdd = abs(a[2]-a[1]);
    rep(i,3,n){
        gcdd = gcd(gcdd,abs(a[i]-a[i-1]));
    }
    rep(i,1,n){
        if((k-a[i])%gcdd==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}