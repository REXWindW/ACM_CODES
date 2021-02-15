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
int a[5];
void solve(){
    rep(i,1,3){
        cin>>a[i];
    }
    sort(a+1,a+1+3,greater<int>());
    int res = 0;
    int tot = 0;
    rep(i,1,3){
        tot+=a[i];
        if(tot>=500){
            tot-=100;
            res+=tot;
            tot=0;
        }
    }
    res+=tot;
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}