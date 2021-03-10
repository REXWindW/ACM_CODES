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

int n,k;
string s;

void solve(){
    cin>>n>>k;
    cin>>s;
    if(k*2>=n){cout<<"NO"<<endl;return;}
    bool flag = 1;
    rep(i,0,k-1){
        if(s[i]!=s[n-1-i]){
            flag = 0;break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}