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
char hc;
const int MAXN = 114514;
int a[MAXN];
void solve(){
    cin>>n;
    int typ = n%2;
    bool flag = 0;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
        if(i%2==typ){
            if(hc%2==typ) flag = 1;
        }
    }
    if(typ==1){
        if(flag) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else if(typ==0){
        if(flag) cout<<2<<endl;
        else cout<<1<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}