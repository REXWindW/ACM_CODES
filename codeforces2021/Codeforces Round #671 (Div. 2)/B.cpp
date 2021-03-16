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
ll x;
void solve(){
    cin>>x;
    ll base = 2;
    int res = 0;
    ll now = 1;
    while(x>=now*(now+1)/2){
        x-=now*(now+1)/2;
        res++;
        base<<=1;
        now = base-1;
    } 
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}