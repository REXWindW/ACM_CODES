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
int n;
const int MAXN = 114514*2;
int a[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    sort(a+1,a+1+n);
    cout<<min(n-2,a[n-1]-1)<<endl;

}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}