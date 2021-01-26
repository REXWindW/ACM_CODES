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
//组合数板子
const int MAXN = 3e5+5;
const int med = 1e9+7;
ll jc[MAXN];
ll qpow(ll d,ll c){//快速幂
    ll res = 1;
    while(c){
        if(c&1) res=res*d%med;
        d=d*d%med;c>>=1;
    }return res;
}
inline ll niyuan(ll x){return qpow(x,med-2);}
void initjc(){//记得要初始化阶乘
    jc[0] = 1;
    rep(i,1,MAXN-1) jc[i] = jc[i-1]*i%med;
}
inline int C(int n,int m){//n是下面的
    if(n<m) return 0;
    return jc[n]*niyuan(jc[n-m])%med*niyuan(jc[m])%med;
}
//组合数板子
const int MAXX = 114514;
int a[MAXX],cnt[MAXX];
int n,k;//选k个人

void solve(){
    cin>>n>>k;
    rep(i,1,1000) cnt[i]=0;
    int hc;
    rep(i,1,n){
        cin>>hc;
        cnt[hc]++;//统计每个数字出现几次
    }
    int now=0;
    repb(i,1000,1){//找到需要对哪个数字进行讨论
        if(now+cnt[i]>=k){
            cout<<C(cnt[i],cnt[i]+now-k)<<endl;//计算排列组合
            return;
        }
        now+=cnt[i];
    }
}

int main(){
    initjc();
    int z;
    cin>>z;
    while(z--) solve();
}