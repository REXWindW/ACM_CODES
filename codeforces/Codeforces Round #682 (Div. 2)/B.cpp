#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
int n;
map<int,bool> mp;
void solve(){
    mp.clear();
    int hc;
    bool flag = 0;
    cin>>n;
    rep(i,1,n){
        cin>>hc;
        if(mp[hc]){
            flag = 1;
        }
        mp[hc] = 1;
    }if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}