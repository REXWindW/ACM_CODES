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
ll a[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    ll d,cost=0;//cnt是前面加了后面还没减掉的（后面要用到的时候用
    rep(i,2,n){
        if(a[i-1]<0){//前面加的情况
            cost+=-(a[i-1]);
            a[i-1]=0;
        }
        //前减后加
        d = a[i-1];
        a[i]+=d;
        a[i-1]=0;
    }
    cout<<cost<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}