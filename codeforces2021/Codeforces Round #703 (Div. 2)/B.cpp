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
typedef pair<ll,ll> pii;
#define ft first
#define sd second
#define mkp make_pair
pii a[MAXN];
inline ll dis(pii a,pii b){
    return abs(a.ft-b.ft)+abs(a.sd-b.sd);
}

void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i].ft>>a[i].sd;
    }
    
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}