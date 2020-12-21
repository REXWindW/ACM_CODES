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
const int MAXN = 2e5+5;
int n;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int lb = 1;
    rep(rb,1,n){
        while(a[rb]-a[lb]>k) lb++;
        
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}