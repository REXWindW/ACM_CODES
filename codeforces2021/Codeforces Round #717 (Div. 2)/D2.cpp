#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,q;
const int MAXN = 114514;
int a[MAXN];
int bz[MAXN][24];
bool ntprm[MAXN];
int rb[MAXN];//每个数字到右边可以到多远
int pre[MAXN];//每个质因子上次出现在哪里
vector<int> prm;int cprm;//计数
void init(){
    rep(i,2,1e5){
        if(ntprm[i]) continue;
        prm.push_back(i);
        for(int j=i;j<=1e5;j+=i){
            ntprm[j] = 1;
        }
    }
    cprm = prm.size();
}
void solve(){
    cin>>n>>q;
    rep(i,1,n) cin>>a[i];
    rep(i,0,cprm-1) pre[prm[i]] = n+1;
    rb[n+1]=n+1;
    repb(i,n,1){
        rb[i] = rb[i+1];
        rep(j,0,cprm-1){
            if(prm[j]*prm[j]>a[i]) break;
            if(a[i]%prm[j]==0){
                while(a[i]%prm[j]==0) a[i]/=prm[j];
                rb[i] = min(rb[i],pre[prm[j]]);
                pre[prm[j]] = i;
            }
        }
        if(a[i]!=1){
            rb[i] = min(rb[i],pre[a[i]]);
            pre[a[i]] = i;
        }
    }
    rep(i,1,n) bz[i][0] = rb[i];
    bz[n+1][0] = n+1;
    rep(j,1,20){
        bz[n+1][j] = n+1;
        rep(i,1,n){
            bz[i][j] = bz[bz[i][j-1]][j-1];//倍增
        }
    }   
    int l,r;
    while(q--){
        cin>>l>>r;
        int cnt = 1;
        repb(j,20,0){
            if(bz[l][j]<=r){
                cnt+=(1<<j);
                l = bz[l][j];
            }
        }
        cout<<cnt<<endl;
    }
}

int main(){
    init();
    solve();
}