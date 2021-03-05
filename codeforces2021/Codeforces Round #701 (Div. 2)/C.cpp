#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
//b<a<b^2
ll x,y;
ll res;
void solve(){
    cin>>x>>y;
    ll bj = min((ll)sqrt(x+1)-1,y-1);
    //1-sqrt(x+1)求和b-1
    res = bj*(bj+1)/2;
    ll r=0;
    //l是b+1值
    for(ll l=bj+3;l<=min(x,y+1);l=r+1){
        r = min(min(x,y+1),x/(x/l));
        res+=(r-l+1)*(x/l);
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}