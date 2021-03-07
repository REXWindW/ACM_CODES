#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//大于k的,和偶数？
int n,k;
vector<int> vec;

void solve(){
    cin>>n>>k;
    vec.clear();
    int st = k/2;
    if(k%2) st++;
    rep(i,st,k-1) vec.push_back(i);
    rep(i,k+1,n) vec.push_back(i);
    cout<<vec.size()<<endl;
    int siz = vec.size();
    rep(i,0,siz-1) cout<<vec[i]<<' ';
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}