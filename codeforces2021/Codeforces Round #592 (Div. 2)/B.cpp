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
const int MAXN = 2e6+5;
int n;
bool a[MAXN];
void solve(){
    cin>>n;
    char hc;
    int cnt = 0,maxx = 0,minn = n+1;
    rep(i,1,n){
        cin>>hc;
        a[i]=hc-'0';
        cnt+=a[i];
        if(a[i]) maxx = i;
        if(a[i]) minn = min(minn,i);
    }
    cout<<max(cnt+n,max(maxx*2,(n-minn+1)*2))<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}