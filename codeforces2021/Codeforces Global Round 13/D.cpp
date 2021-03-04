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
int u,v;
void solve(){
    cin>>u>>v;
    int bs = 1;
    int cu =0, cv = 0;
    rep(i,0,30){
        if(u&bs) cu++;
        if(v&bs) cv++;
        if(cu<cv){
            cout<<"NO"<<endl;
            return;
        }
        bs<<=1;
    }
    //cout<<cu<<' '<<cv<<endl;
    if(u<=v) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}