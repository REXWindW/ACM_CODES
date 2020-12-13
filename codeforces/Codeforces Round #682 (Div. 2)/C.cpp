#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
int n,m;
void solve(){
    cin>>n>>m;
    int hc;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            if((i+j)%2!=hc%2) hc++;
            cout<<hc<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}