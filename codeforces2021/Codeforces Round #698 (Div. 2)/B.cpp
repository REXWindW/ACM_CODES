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
int a[11];
int q,d;
void solve(){
    cin>>q>>d;
    int hc;
    rep(i,0,9) a[i] = INF;
    rep(i,1,10){
        hc = d*i;
        a[hc%10] = min(a[hc%10],hc); 
    }
    int x;
    while(q--){
        cin>>x;
        if(x>=a[x%10]) cout<<"YES"<<endl;
        else if(x>=d*10) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}