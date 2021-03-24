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
const int MAXN = 114514*2;
int a[MAXN];
int b[MAXN];
//朋友的开心值是最大加最小
//最大的一批数字肯定要个k=1的人
int n,k;
ll res;
void solve(){
    res = 0;
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    int cnt1 = 0;
    rep(i,1,k){
        cin>>b[i];
        if(b[i]==1) cnt1++;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+k,greater<int>());
    //k=x时，拿最小的x-1个和最大的1个
    int r = n,l = 1;//还在的数字
    rep(i,1,cnt1){
        res+=a[r]*2;
        r--;
    }
    rep(i,1,k){
        if(b[i]==1) continue;
        res+=a[r]+a[l];
        r--;
        l+=b[i]-1;
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}