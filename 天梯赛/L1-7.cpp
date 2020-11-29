#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
const int MAXN = 1e5+5;
int n,m;
ll qz[66];
string hc;
void solve(){
    cin>>n>>m;
    qz[n] = 1;
    repb(i,n-1,1){
        qz[i] = qz[i+1]<<1;
    }
    while(m--){
        cin>>hc;
        int now = 1;
        rep(i,0,n-1){
            if(hc[i]=='y')continue;
            else now+=qz[i+1];
        }
        cout<<now<<endl;
    }
}
int main(){
    solve();
}