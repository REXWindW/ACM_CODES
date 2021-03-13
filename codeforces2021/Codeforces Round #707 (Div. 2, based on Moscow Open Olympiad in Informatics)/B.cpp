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
int cf[MAXN];
int a[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        cf[i]=0;
    }
    int top;
    rep(i,1,n){//开始模拟
        top = i;
        cf[max(1,top-a[i]+1)]++;
        cf[top+1]--;
    }
    int now = 0;
    rep(i,1,n){
        now+=cf[i];
        if(now>0) cout<<1<<' ';
        else cout<<0<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}