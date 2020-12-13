#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
int n;
void solve(){
    cin>>n;
    rep(i,1,n) cout<<1<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}