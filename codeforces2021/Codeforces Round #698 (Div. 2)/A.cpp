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
const int MAXN = 114;
int cnt[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n) cnt[i]=0;
    int maxx = 0;
    int hc;
    rep(i,1,n){
        cin>>hc;
        cnt[hc]++;
        maxx = max(maxx,cnt[hc]);
    }
    cout<<maxx<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}