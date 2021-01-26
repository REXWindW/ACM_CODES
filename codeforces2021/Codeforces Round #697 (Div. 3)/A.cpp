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
ll p[114514];
void init(){
    p[0] = 1;
    rep(i,1,60){
        p[i] = p[i-1]*2;
    }
}
void solve(){
    ll n;  
    cin>>n;
    if(*lower_bound(p+1,p+1+60,n)==n||n==1){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}