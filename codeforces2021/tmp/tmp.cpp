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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int a,b;
int n;
void solve(){
    a=0,b=1;
    cin>>n;
    int u,v;
    char hc;
    int gcdd;
    rep(i,1,n){
        cin>>u>>hc>>v;
        gcdd = gcd(b,v);
        b *= v/gcdd;
        a = a*(v/gcdd)+u*(b/v);
        if(a){
            gcdd = gcd(b,abs(a));
            a/=gcdd,b/=gcdd;
        }
    }
    bool f=0;
    if(a==0){
        cout<<0<<endl;return;
    }
    if(a/b) cout<<a/b,f=1;
    if(a%b){ 
        if(f) cout<<' ';
        cout<<a%b<<'/'<<b;
    }
    
    cout<<endl;
}

int main(){
    solve();
}