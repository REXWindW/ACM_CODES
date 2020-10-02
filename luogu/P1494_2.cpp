#pragma GCC optimize(2)
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
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
const int MAXN = 5e4+5;
int pos[MAXN],cnt[MAXN],a[MAXN];
int n,m;
struct Q{
    int l,r,k;
    friend bool operator < (Q a,Q b){
        return (pos[a.l]^pos[b.l])?pos[a.l]<pos[b.l]:((pos[a.l]&1)?a.r<b.r:a.r>b.r);
    }
}q[MAXN];
ll res;
ll ansfz[MAXN],ansfm[MAXN];//分子分母分开来记录
void Add(int pos){
    res -= cnt[a[pos]]*(cnt[a[pos]]-1);
    cnt[a[pos]]++;
    res += cnt[a[pos]]*(cnt[a[pos]]-1);
}
void Sub(int pos){
    res -= cnt[a[pos]]*(cnt[a[pos]]-1);
    cnt[a[pos]]--;
    res += cnt[a[pos]]*(cnt[a[pos]]-1);
}
int main(){
	cin>>n>>m;
    int siz = sqrt(n);
    rep(i,1,n){
        cnt[i] = 0;
        cin>>a[i];
        pos[i] = i/siz;
    }
    rep(i,1,m){cin>>q[i].l>>q[i].r;q[i].k=i;}
    sort(q+1,q+1+m);
    res = 0;
    int l = 1,r = 0;
    rep(i,1,m){
        while(l>q[i].l) Add(--l);
        while(l<q[i].l) Sub(l++);
        while(r<q[i].r) Add(++r);
        while(r>q[i].r) Sub(r--);
        ansfz[q[i].k] = res;
        ansfm[q[i].k] = (ll)(r-l+1)*(r-l);
    }
    rep(i,1,m){
        if(ansfz[i]==0) cout<<"0/1"<<endl;
        else cout<<ansfz[i]/gcd(ansfz[i],ansfm[i])<<'/'<<ansfm[i]/gcd(ansfz[i],ansfm[i])<<endl;
    }
}