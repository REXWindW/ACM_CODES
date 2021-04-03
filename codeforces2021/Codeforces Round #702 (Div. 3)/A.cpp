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
int a[MAXN];
int n;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int now = a[1];
    int cnt = 0;
    rep(i,2,n){
        if(a[i]>now){
            while(now*2<a[i]){
                now*=2;
                cnt++;
            }
        }
        else if(a[i]<now){
            int tmp = a[i];
            while(tmp*2<now){
                tmp*=2;
                cnt++;
            }
        }
        now = a[i];
    }
    cout<<cnt<<endl;
    return;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}