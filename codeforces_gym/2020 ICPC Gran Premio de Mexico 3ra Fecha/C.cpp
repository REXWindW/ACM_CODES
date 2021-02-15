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
ll n,m;
void solve(){
    cin>>n>>m;
    n++,m++;
    cout<<(n*(n+1)/2)*m%((int)1e9+7)<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}