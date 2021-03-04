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
const int MAXN = 114;
int n,u,v;
int a[MAXN];
void solve(){
    cin>>n>>u>>v;
    rep(i,1,n)
        cin>>a[i];
    bool flag1 = 1;//全在一列上的情况
    bool flag2 = 1;
    rep(i,2,n){
        if(a[i]!=a[i-1]) flag1 = 0;
        if(abs(a[i]-a[i-1])>1) flag2 = 0;
    }
    if(flag1) cout<<v+min(u,v)<<endl;
    else if(flag2) cout<<min(u,v)<<endl;
    else cout<<0<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}