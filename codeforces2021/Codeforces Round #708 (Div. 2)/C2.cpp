#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define int ll
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
ll n,k;
//vector<int> res;
void solve(){
    cin>>n>>k;
    rep(i,1,k-3){
        cout<<1<<' ';
        n--;
    }
    if(n%2){
        cout<<n/2<<' '<<n/2<<' '<<1<<endl;
    }
    else{
        if((n/2)%2){//n/2为奇数
            cout<<n/2-1<<' '<<n/2-1<<' '<<2<<endl;
        }
        else{
            cout<<n/2<<' '<<n/4<<' '<<n/4<<endl;
        }
    }
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}