#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

int a[114514];
const int MAXX = 2e9+1;
int n,cnt;
void init(){
    cnt = 0;
    int now = 3;//a的值
    while(now*now<=MAXX){
        a[++cnt] = now*now;
        now+=2;
    }
}

void solve(){
    cin>>n;
    int tmp = 2*n-1;
    int px = upper_bound(a+1,a+1+cnt,tmp)-a-1;
    cout<<px<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}