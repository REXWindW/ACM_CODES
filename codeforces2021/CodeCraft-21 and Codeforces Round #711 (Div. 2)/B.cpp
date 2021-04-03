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
int n,w;
const int MAXN = 114514;
int a[MAXN],b[MAXN];//b记录是2的几次
int pw[MAXN];
int cnt[40];

void init(){
    pw[0]=1;
    rep(i,1,31) pw[i] = pw[i-1]<<1;
}

void solve(){
    rep(i,0,39) cnt[i]=0;
    cin>>n>>w;
    rep(i,1,n){
        cin>>a[i];
        b[i]=0;
        while(a[i]!=1){
            a[i]>>=1;b[i]++;
        }
        cnt[b[i]]++;
    }
    bool flag = 1;
    int res = 0;
    while(flag){
        res++;
        int nw = w;
        flag = 0;
        repb(i,31,0){
            if(cnt[i]) flag = 1;
            while(cnt[i]&&nw>=pw[i]){
                nw-=pw[i],cnt[i]--;
            }
        }
    }
    cout<<res-1<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}