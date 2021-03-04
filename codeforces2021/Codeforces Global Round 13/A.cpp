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
int n,q;
int a[MAXN];
int cnt[3];
;void solve(){
    cin>>n>>q;
    rep(i,1,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int typ,x;
    while(q--){
        cin>>typ>>x;
        if(typ==1){
            cnt[a[x]]--;
            a[x]=1-a[x];
            cnt[a[x]]++;
        }
        if(typ==2){
            if(cnt[1]>=x) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}

int main(){
    solve();
}