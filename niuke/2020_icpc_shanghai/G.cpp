#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
ll n;
void solve(){
    cin>>n;
    ll z = n/3;
    ll ji = z*2;
    ll ou = z;
    ll yu = n%3;
    ji += yu;
    ll res = (n*(n-1)-ji*(ji-1))>>1;
    cout<<res<<endl;
}

int main(){
    solve();
}