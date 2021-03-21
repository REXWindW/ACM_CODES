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
const int MAXN = 114;
int sum;
int a[MAXN];
int maxx;
int n;
void solve(){
    maxx = sum = 0;
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        maxx = max(a[i],maxx);
        sum+=a[i];
    }
    if(maxx<sum-maxx) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    solve();
}