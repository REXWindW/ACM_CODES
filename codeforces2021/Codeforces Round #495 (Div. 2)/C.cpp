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
#define int ll
const int MAXN = 114514;

int vis[MAXN];
int lft[MAXN],rit[MAXN];
int cntl,cntr;//在左边出现过的和在右边出现过的数量
int a[MAXN];
int n;
void solve(){
    cin>>n;
    int res = 0;
    rep(i,1,n){
        cin>>a[i];
        if(rit[a[i]]==0) cntr++;
        rit[a[i]]++;
    }
    rep(i,1,n-1){
        bool flag = 0;
        if(lft[a[i]]==0){
            cntl++;
            lft[a[i]]++;
            flag = 1;
        }
        if(rit[a[i]]>0){
            if(rit[a[i]]==1) cntr--;
            rit[a[i]]--;
            //flag = 1;
        }
        if(flag) res+=cntr;
        //cout<<i<<' '<<res<<endl;
    }
    cout<<res<<endl;
}

signed main(){
    solve();
}