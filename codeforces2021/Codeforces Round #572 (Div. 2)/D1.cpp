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
int n,u,v;
const int MAXN = 114514;
int c[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n-1){
        cin>>u>>v;
        c[u]++;c[v]++;
    }
    bool flag = 1;
    rep(i,1,n){
        if(c[i]!=1&&c[i]<3){
            flag = 0;break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    solve();
}