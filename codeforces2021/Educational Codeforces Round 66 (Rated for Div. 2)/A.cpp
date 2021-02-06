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
#define int ll
ll n,k,t;
void solve(){
    cin>>n>>k;
    int cnt = 0;
    while(n){
        if(n%k==0){
            n/=k;cnt++;
        }
        else{
            t=n%k;
            cnt+=t;
            n-=t;
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}