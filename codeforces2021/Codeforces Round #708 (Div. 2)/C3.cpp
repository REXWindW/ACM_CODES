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
int n,k;
void deal(ll n,ll k){
    if(k==3){
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
    else{
        if(n%2){
            cout<<n/2<<' ';
            deal(n-n/2,k-1);
        }
        else{
            if((n/2)%2){//n/2为奇数
                cout<<n/2-1<<' ';
                deal(n-(n/2-1),k-1);
            }
            else{
                cout<<n/2<<' ';
                deal(n-(n/2),k);
            }
        }
    }
}
void solve(){
    cin>>n>>k;
    deal(n,k);
}
signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}