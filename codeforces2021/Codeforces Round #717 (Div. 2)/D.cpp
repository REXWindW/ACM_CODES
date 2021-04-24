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
vector<int> prm;
int maxp[MAXN];//每个质数当前的最右位置
bool ntprim[MAXN];
int l[MAXN];//往左边最早与之冲突的位置
int cp;
int cf[MAXN],sum[MAXN];
int nzt[MAXN];//记录下一个组头在哪里
int minzt[MAXN];//记录这组的minn冲突位置
void init(){//质数筛查
    rep(i,2,100000){
        if(ntprim[i]) continue;
        prm.push_back(i);
        for(int j=2*i;j<=100000;j+=i){
            ntprim[j] = 1;
        }
    }
    cp = prm.size();
}
inline void solve(){
    //cout<<cp<<endl;
    cin>>n>>q;
    rep(i,1,n){
        l[i] = l[i-1];
        cin>>a[i];
        int sqr = sqrt(a[i]);
        rep(j,0,cp-1){
            if(prm[cp]>sqr||a[i]==1) break;
            if(a[i]%prm[j]==0){
                while(a[i]%prm[j]==0) a[i]/=prm[j];
                l[i] = max(l[i],maxp[j]);
                maxp[j] = i;//更新位置
            }
        }
        if(a[i]!=1){
            l[i] = max(l[i],maxp[a[i]]);
            maxp[a[i]] = i;//更新位置
        }
    }
    //rep(i,1,n) cout<<l[i]<<' ';
    //cout<<endl;
    int nowl = 0;
    rep(i,1,n){
        if(l[i]>=nowl){
            cf[i] = 1;//表示为一个组头
            nowl = i;
        }
        minzt[nowl] = max(minzt[nowl],l[i]);//最小冲突位置
        sum[i] = sum[i-1]+cf[i];
    }
    /*
    rep(i,1,n) cout<<cf[i]<<' ';
    cout<<endl;
    rep(i,1,n) cout<<minzt[i]<<' ';
    cout<<endl;
    */
    int now = n+1;
    repb(i,n,1){
        nzt[i] = now;
        if(cf[i]) now = i;//记录下一个组头的位置
    }
    int l,r,res=0;
    while(q--){
        cin>>l>>r;
        res = sum[r]-sum[l-1];//有几个组头
        if(!cf[l]){
            if(minzt[nzt[l]]<=l);
            else res++;
        }
        cout<<res<<endl;
    }
}

int main(){
    init();
    solve();
}