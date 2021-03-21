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
#define int ll
int n,x,y;
void solve(){
    cin>>n>>x>>y;
    if(n==1){cout<<min(x,y)<<endl;return;}
    while(x!=y){
        if(x<y){
            swap(x,y);
        }
        x=(x-2)/n+1;
    }
    cout<<x<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}