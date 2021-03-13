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
int n;
void solve(){
    cin>>n;
    if((n-1)%2==0){//这种情况,每个队伍一半输一半即可
        rep(i,1,n){
            rep(j,1,n-i){
                if(j%2) cout<<1<<' ';
                else cout<<-1<<' ';
            }
        }
        cout<<endl;
    }
    else{
        rep(i,1,n){
            rep(j,i+1,n){
                if(i%2&&j==i+1) cout<<0<<' ';
                else if((i+j)%2==0) cout<<1<<' ';
                else cout<<-1<<' ';
            }
        }
        cout<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}