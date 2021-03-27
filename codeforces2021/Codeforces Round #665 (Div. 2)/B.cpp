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
int a[10],b[10];
void solve(){
    rep(i,0,2) cin>>a[i];
    rep(i,0,2) cin>>b[i];
    //只有1和2的积有用，12能合尽量合成
    int tmp = min(a[2],b[1]);
    int res = 0;
    a[2]-=tmp;
    b[1]-=tmp;
    res+=tmp*2;
    //相同的尽量抵消,0不能浪费
    rep(i,1,2){
        tmp = min(a[i],b[i]);
        a[i]-=tmp;
        b[i]-=tmp;//接下来每种只会剩下来一个
    }
    tmp = min(a[0],b[2]);
    a[0]-=tmp;b[2]-=tmp;
    //b0不管，处理b1和b2
    //b2a1
    //a2a1
    //a2b1(不可能)
    tmp = min(b[2],a[1]);
    b[2]-=tmp;
    a[1]-=tmp;
    res-=tmp*2;
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}