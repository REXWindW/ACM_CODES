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

int n;
const int MAXN = 114514;
int a[MAXN];
int c[MAXN];
int b[MAXN];
void solve(){
    cin>>n;
    char hc;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
    }
    c[1]=a[1]+1;
    b[1] = 1;
    rep(i,2,n){
        if(a[i]+1==c[i-1]){
            b[i]=0;
            c[i]=a[i];
        }
        else{
            b[i]=1;
            c[i]=a[i]+1;
        }
    }
    rep(i,1,n) cout<<b[i];
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}