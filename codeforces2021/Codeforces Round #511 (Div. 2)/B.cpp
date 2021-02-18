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
int n,x,y;
void solve(){
    cin>>n;
    int maxx = 0;
    rep(i,1,n){
        cin>>x>>y;
        maxx = max(maxx,x+y);
    }
    cout<<maxx<<endl;
}

int main(){
    solve();
}