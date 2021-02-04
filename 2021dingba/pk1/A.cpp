#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 2e6+5;
int n,m;
int typ,x;//typ=0行,1列
ll sumh,suml;
int cnth,cntl;//cnth还有几行没被砍过
bool vish[MAXN],visl[MAXN];
ll res;
void solve(){
    scanf("%lld%lld",&typ,&x);
    if(typ==0){
        if(vish[x]){cout<<0<<endl;return;}
        res=sumh+x*n*cntl;
        vish[x] = 1;
        suml-=(x-1)*n;
        cnth--;
    }
    else if(typ==1){
        if(visl[x]){cout<<0<<endl;return;}
        res=suml+x*cnth;
        visl[x] = 1;
        sumh-=x-n;
        cntl--;
    }
    printf("%lld\n",res);
}

signed main(){
    scanf("%lld%lld",&n,&m);
    sumh=suml=0;
    cnth=cntl=n;
    rep(i,1,n){
        sumh+=i-n;
        suml+=(i-1)*n;//lie(x)=suml+x*n;
    }
    while(m--) solve();
}