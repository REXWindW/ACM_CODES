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
int n,q,k;
const int MAXN = 114514;
int a[MAXN];
int sum[MAXN];
int ran[MAXN];//范围
void solve(){
    cin>>n>>q>>k;
    rep(i,1,n) cin>>a[i];
    //每个数看前后两个数确定有几个可能位置,做前缀和
    //查询时边界位置特殊处理
    sum[0]=0;
    sum[1]=ran[1] = a[2]-a[1]; 
    rep(i,2,n){
        ran[i]=a[i+1]-a[i-1]-2;
        sum[i] = sum[i-1]+ran[i];
    }
    int l,r;
    while(q--){
        cin>>l>>r;
        if(l==r) cout<<k-1<<endl;
        else cout<<(a[l+1]-2)+sum[r-1]-sum[l]+(k-a[r-1]-1)<<endl;
    }
}

int main(){
    solve();
}