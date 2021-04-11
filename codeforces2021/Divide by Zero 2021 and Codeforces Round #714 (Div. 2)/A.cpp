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
int n,k;
void solve(){
    cin>>n>>k;
    if(k*2>=n){
        cout<<-1<<endl;
        return;
    }
    //qian 2k+1个数字用来构造峰值
    rep(i,1,2*k+1){
        if(i%2) cout<<i/2+1<<' ';
        else cout<<2*k+1+1 - i/2<<' ';
    }
    rep(i,2*k+2,n){
        cout<<i<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}