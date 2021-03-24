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
#define int ll
int n;
const int MAXN = 114514;
int h[MAXN];

void solve(){
    cin>>n;
    rep(i,0,n-1) cin>>h[i];
    int rst = h[0];
    h[0] = 0;
    bool flag = 1;
    rep(i,1,n-1){
        if(h[i]>i){
            rst+=h[i]-i;
            h[i]=i;
        }
        else{
            rst-=i-h[i];
            if(rst<0){
                flag = 0;break;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}