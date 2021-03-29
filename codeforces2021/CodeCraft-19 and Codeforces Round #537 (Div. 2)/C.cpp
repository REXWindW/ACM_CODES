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
int p[MAXN];
int n,k,A,B;
int tot;
void deal(int l,int r){

}

void solve(){
    cin>>n>>k>>A>>B;
    rep(i,1,k) cin>>p[i];
    tot = 1<<n;
    rep(i,1,n){
        
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}