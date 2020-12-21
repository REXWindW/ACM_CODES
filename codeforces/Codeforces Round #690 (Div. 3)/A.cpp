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
int n;
const int MAXN = 456;
int a[MAXN],b[MAXN];
void solve(){
    cin>>n;
    int pos;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        if(i%2){
            b[i] = a[i/2+1];
        }
        else{
            b[i] = a[n-i/2+1];
        }
    }
    rep(i,1,n) cout<<b[i]<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}