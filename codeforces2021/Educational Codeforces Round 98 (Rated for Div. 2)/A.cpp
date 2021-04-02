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
int x,y;
void solve(){
    cin>>x>>y;
    if(x<y) swap(x,y);
    int res = y*2;
    x-=y;
    int ci = x/2;
    int ys = x%2;
    if(ys==1){
        res += ci*4+1;
    }
    else{
        if(ci!=0) res += (ci-1)*4+3;
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}