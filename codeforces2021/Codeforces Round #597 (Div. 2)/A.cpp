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
void solve(){
    int aa,bb;
    cin>>aa>>bb;
    if(gcd(aa,bb)==1)cout<<"Finite"<<endl;
    else cout<<"Infinite"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}