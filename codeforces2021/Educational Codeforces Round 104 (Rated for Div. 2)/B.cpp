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
int n,k;
void solve(){
    cin>>n>>k;
    k--;
    if(n%2==0){cout<<k%n+1<<endl;return;}//偶数不会碰头
    int met = k/(n/2);
    cout<<(k+met)%n+1<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}