#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//j-(i-1)=sum[j]-sum[i-1]
//turn out to be
//sum[j]-j=sum[i-1]-(i-1);//ok
const int MAXN = 114514;
int a[MAXN],sum[MAXN];
map<int,int> mp;
int n;
void solve(){
    mp.clear();
    mp[0]=1;//sum[0]-0
    cin>>n;
    char hc;
    sum[0] = 0;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
        sum[i] = sum[i-1]+a[i];
    }
    int now;
    ll res = 0;
    rep(i,1,n){
        now = sum[i]-i;
        res+=mp[now];
        mp[now]++;
    }
    cout<<res<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}