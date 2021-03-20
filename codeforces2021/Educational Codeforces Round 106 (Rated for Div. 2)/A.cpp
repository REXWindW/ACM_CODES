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
int k1,k2,n;
int w,b;
void solve(){
    cin>>n>>k1>>k2;
    cin>>w>>b;
    //放多少白色
    if(k1<k2) swap(k1,k2);
    int cha = k1-k2;
    int pw = k2+cha/2;
    int pb = (n-k1)+cha/2;
    if(pw>=w&&pb>=b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}