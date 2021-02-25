#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
int n,m;
const int MAXN = 5e5+5;;
int a[MAXN];
ll sum[MAXN];
void solve(){
    sum[0]=0;
    cin>>n>>m;
 	if(m!=0) return;
    rep(i,1,n){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    //for m = 0;
   	scanf("%d",&m);
    int u,v;
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        if(v<u) swap(u,v);
        printf("%lld\n",min(sum[v-1]-sum[u-1],sum[n]-sum[v-1]+sum[u-1]) );
    }
}

int main(){
    solve();
}