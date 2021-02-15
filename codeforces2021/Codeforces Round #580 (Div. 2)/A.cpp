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

void solve(){
    int n,maxx1 = 0;
    cin>>n;
    int hc;
    rep(i,1,n){
        cin>>hc;
        maxx1 = max(maxx1,hc);
    }
    cin>>n;
    int maxx2 = 0;
    rep(i,1,n){
        cin>>hc;
        maxx2 = max(maxx2,hc);
    }
    cout<<maxx1<<' '<<maxx2<<endl;
}

int main(){
    solve();
}