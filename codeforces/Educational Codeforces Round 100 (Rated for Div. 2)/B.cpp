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
const int MAXN = 114514;//2<=n<=50
int a[MAXN];
ll s[2];
int n;

void solve(){
    cin>>n;
    s[0] = s[1] = 0;
    rep(i,1,n){
        cin>>a[i];
        s[i%2]+=a[i];
    }
    int typ=s[0]>=s[1]?0:1;
    rep(i,1,n){
        if(i%2==typ) cout<<a[i]<<' ';
        else cout<<1<<' ';
    }
    cout<<endl;
}
//看奇数偶数位上哪个和大
//然后就1,a[2],1,a[4]这样?
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}