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
const int MAXN = 1e5+5;
ll a[MAXN];
const ll LINF = 1ll<<60;
int n;
void solve(){
    cin>>n;
    int gou = 0;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll tot = 0;
    rep(i,1,n){
        if(a[i]>=n) gou = i;
    }
    if(!gou) tot = n;
    else tot = (n-gou)+a[gou];
    if(tot%2)
        cout<<"First"<<endl;
    else{
        cout<<"Second"<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}