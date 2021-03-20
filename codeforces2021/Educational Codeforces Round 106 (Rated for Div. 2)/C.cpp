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
ll c[MAXN];
ll sum[MAXN];
ll minn[4];
ll cnt[3];
const ll LINF = 1ll<<60;
void solve(){
    cin>>n;
    sum[0] = 0;
    rep(i,1,n){
        cin>>c[i];
        sum[i] = sum[i-1]+c[i];
    }
    minn[0]=c[2];
    minn[1]=c[1];//奇数偶数上最小的
    ll res = c[1]*n+c[2]*n;
    ll tmp;
    cnt[0]=cnt[1]=0;//剩下来有几根
    rep(i,3,n){
        cnt[i%2]++;
        minn[i%2]=min(minn[i%2],c[i]);//更新
        tmp = minn[0]*(n-cnt[0])+minn[1]*(n-cnt[1]);
        tmp += sum[i]-minn[0]-minn[1];//剩下的几段
        res = min(res,tmp);
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}