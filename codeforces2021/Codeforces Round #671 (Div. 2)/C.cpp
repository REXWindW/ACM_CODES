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

const int MAXN = 114514;
int a[MAXN];//rating
int n,x;
int summ;
void solve(){
    summ = 0;
    cin>>n>>x;
    rep(i,1,n) cin>>a[i],summ+=a[i];
    int cntx = 0;//数几个x
    rep(i,1,n) if(a[i]==x) cntx++;
    if(cntx==n){cout<<0<<endl;return;}
    if(summ%n==0){//一场/两场的情况
        if(summ/n==x||cntx) {cout<<1<<endl;return;}
    }
    if(cntx){cout<<1<<endl;return;}
    cout<<2<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}