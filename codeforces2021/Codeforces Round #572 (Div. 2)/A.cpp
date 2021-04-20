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
const int MAXN = 114514;
int hc;
int a[MAXN];
int n;
int c[4];
void solve(){
    char hc;
    cin>>n;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
        c[a[i]]++;
    }
    if(c[1]==c[0]){
        cout<<2<<endl;
        rep(i,1,n-1)cout<<a[i];
        cout<<' ';
        cout<<a[n]<<endl;
    }
    else{
        cout<<1<<endl;
        rep(i,1,n) cout<<a[i];
        cout<<endl;
    }
}

int main(){
    solve();
}