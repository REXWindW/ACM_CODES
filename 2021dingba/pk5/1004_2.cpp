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
int n,m;
void solve(){
    cin>>n>>m;
    char hc;
    int cnt = 0;
    rep(i,1,n){
        rep(j,1,m){
            cin>>hc;
            if(hc=='o')cnt++;
        }
    }
    if(cnt%2==0){
        if(cnt==0&&(n%2==0||m%2==0)){cout<<"Happy!!!"<<endl;return;}
    }
    cout<<"Angry!!!"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}