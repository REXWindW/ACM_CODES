#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
ll cnt[MAXN];//用那个省时间的方法
ll a[MAXN];
ll cas;
int n;
int tot;
void div(ll x){
    int sqr = sqrt(x);
    rep(i,2,sqr){
        int bef = cnt[i];
        while(x%i){
            if(cnt[i]!=cas) cnt[i]=cas;
            else if(cnt[i]==cas) cnt[i]=0;
            x/=i;
        }
        if(bef==cas&&cnt[i]!=cas) tot--;
        else if(bef!=cas&&cnt[i]==cas) tot++;
    }
    if(x!=1){
        if(cnt[x]!=cas){cnt[x]=cas;tot++;}
        else if(cnt[x]==cas){cnt[x]=0;tot--;}
    }
}
void solve(){
    cin>>n;
    ll res = 0;
    cas=0;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        rep(j,i,n){
            cas++;
            tot=0;//记录几个质因子上是1
            rep(k,i,j)
                div(a[k]);
            cout<<i<<' '<<j<<' '<<tot<<endl;
            if(tot==0)res++;
        }
    }
    cout<<res<<endl;
}

signed main(){
    solve();
}