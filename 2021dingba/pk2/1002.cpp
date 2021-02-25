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
const int MAXN = 114514;
ll a[MAXN];
ll sum[MAXN];
int n;
bool OK(ll x){
    ll l = 1,r = 114514;
    while(l<r){//二分找第一个大于等于x
        ll mid = (l+r)>>1;
        if(mid*mid<x) l=mid+1;
        else r = mid; 
    }
    if(r*r==x) return 1;
    else return 0;
}
void solve(){
    cin>>n;
    sum[0]=1;
    rep(i,1,n){
        cin>>a[i];
        sum[i]=sum[i-1]*a[i];
    }
    ll cnt = 0;
    rep(i,1,n){
        rep(j,i,n){
            //cout<<i<<' '<<j<<"judge"<<sum[j]-sum[i-1]<<endl;
            if(OK(sum[j]/sum[i-1])) cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    solve();
}