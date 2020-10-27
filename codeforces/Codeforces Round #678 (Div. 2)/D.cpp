#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define int long long

const int MAXN = 5e5+5;
vector<int>e[MAXN];
int n;
ll a[MAXN];
ll big[MAXN],yz[MAXN],fil[MAXN];
void dfs1(int x,int prev){
    if(e[x].size()==1) {yz[x] = 1; return;}
    for(auto v:e[x]){
        if(v==prev) continue;
        dfs1(v,x);
        yz[x] += yz[v];//统计下面的叶子数量
    }
}
void dfs2(int x,int prev){
    if(e[x].size()==1){
        //cout<<"find"<<x<<endl;
        big[x] = a[x];
        fil[x] = 0;
        return;
    }
    for(auto v:e[x]){
        if(v==prev) continue;
        dfs2(v,x);
        big[x] = max(big[x],big[v]);
    }
    for(auto v:e[x]){
        if(v==prev) continue;
        fil[x] += fil[v];
        fil[x] += yz[v]*(big[x]-big[v]);
    }
    if(a[x]<=fil[x]) fil[x]-=a[x];
    else{//要让max变大
        a[x]-=fil[x];
        fil[x] = 0;
        ll zd = a[x]/yz[x];//big要增大多少
        big[x] += zd;
        if(a[x]%yz[x]){
            big[x]++;
            fil[x] = yz[x]-a[x]%yz[x];
        }
    }
}
void solve(){
	cin>>n;
    int hc;
    yz[1]=fil[1]=big[1]= 0;
    rep(i,2,n){
        fil[i] = yz[i] = big[i] = 0;//之前忘了初始化fil
        cin>>hc;
        e[hc].push_back(i);
        e[i].push_back(hc);
    }
    rep(i,1,n) cin>>a[i];
    dfs1(1,-1);
    dfs2(1,-1);
    /*
    rep(i,1,n){
        cout<<big[i]<<' '<<fil[i]<<endl;
    }
    */
    cout<<big[1]<<endl;
}

signed main(){
	solve();
}