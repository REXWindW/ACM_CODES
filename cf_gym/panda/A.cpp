#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 1e5+5;
int n;
int h[MAXN],w[MAXN];
void solve(){
    cin>>n;
    int maxh = 0;
    rep(i,1,n){
        cin>>h[i]>>w[i];
        maxh = max(maxh,h[i]);
    }
    int l = 0,r = maxh;
    int now;
    while(l+1<r){
        now = (l+r)>>1;
        int toth = 
        rep(i,1,n){
            if()
        }
    }
}

int main(){
    solve();
}