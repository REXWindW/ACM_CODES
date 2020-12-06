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
const int MAXN = 1e4+5;
int cnt[MAXN];
int res;
void solve(){
    res = 0;
    rep(i,0,100) cnt[i] = 0;
    cin>>n>>m;
    int hc;
    rep(i,1,n){
        cin>>hc;
        cnt[hc] = 1;    
    }
    rep(i,1,m){
        cin>>hc;
        if(cnt[hc]) res++;
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}