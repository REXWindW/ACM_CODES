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

const int MAXN = 114514*2;
int a[MAXN];
int n;
int b[MAXN],c[MAXN];
void solve(){
    cin>>n;
    a[0]=a[n+1]=b[0]=b[n+1]=c[0]=c[n+1]=0;
    rep(i,1,n){
        cin>>a[i];
        b[i]=c[i]=a[i];
    }
    int pb=1;
    rep(i,2,n){
        if(b[i]<b[i-1]) break;
        b[i]-=b[i-1];
        pb = i;
    }    
    int pc=n;
    repb(i,n-1,1){
        if(c[i]<c[i+1]) break;
        c[i]-=c[i+1];
        pc = i;
    }
    if(pb==n&&b[n]==0){
        cout<<"YES"<<endl;
        return;
    }
    bool flag = 0;
    int tb,tc;
    rep(i,1,n-1){
        if(i-1>pb) continue;
        if(i+2<pc) continue;
        tb = a[i+1]-b[i-1];
        tc = a[i]-c[i+2];
        if(tb==tc&&tb>=0){
            flag=1;break;
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