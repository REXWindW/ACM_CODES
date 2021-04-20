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
int n,x,hc;
ll minn,maxx;
void solve(){
    cin>>n>>x;
    minn = maxx = 0;
    rep(i,1,n){
        cin>>hc;
        maxx+=(hc+x-1)/x;
        minn+=hc;
    }
    minn = (minn+x-1)/x;
    cout<<minn<<' '<<maxx<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}