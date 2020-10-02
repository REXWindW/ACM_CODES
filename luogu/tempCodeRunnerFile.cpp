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
int cnt[1000010] = {0};
const int MAXN = 2e5+5;
int a[MAXN],b[MAXN];//a读入一开始的序列,b记录修改后的
int pos[MAXN];//分块
int cq,cr;//统计查询修改次数
int R[MAXN][3];//0记位置,1记原本的值,2记修改后的值
ll res;
int ans[MAXN];//记录结果
int n,m;
void Add(int x){if(cnt[x]==0)res++;cnt[x]++;}//带修莫队的add和sub有区别
void Sub(int x){if(cnt[x]==1)res--;cnt[x]++;}
struct Q{
    int l,r,k,t;
    friend bool operator < (Q a,Q b){
        return (pos[a.l]^pos[b.l])?pos[a.l]<pos[b.l]:((pos[a.r]^pos[b.r])?a.r<b.r:a.t<b.t);
        //增加第三关键字,询问的先后顺序,用t或者k应该都行
    }
}q[MAXN];
int main(){
    cin>>n>>m;
    cq = cr = 0;
    int siz = pow(n,2.0/3.0);//这么分块最好,别问
    rep(i,1,n){
        cin>>a[i];
        b[i]=a[i];
        pos[i] = i/siz;
    }
    char hc;
    rep(i,1,m){//读入修改和询问
        cin>>hc;
        if(hc=='Q'){
            cin>>q[cq].l>>q[cq].r;
            q[cq].k=cq;q[cq].t=cr;//注意这时候R[cr]还是没有的,这次询问是在R[cr-1]之后的
            cq++;
        }
        else{
            cin>>R[cr][0]>>R[cr][2];
            R[cr][1] = b[R[cr][0]];
            b[R[cr][0]] = R[cr][2];//在b数组中记录更改
            cr++;
        }
    }
    sort(q,q+cq);
    int l=1,r=0,sjc=0;//时间戳
    res = 0;
    rep(i,0,cq-1){
        while(sjc<q[i].t){
            if(l<=R[sjc][0]&&R[sjc][0]<=r)//判断修改是否在该区间内
                Sub(R[sjc][1]),Add(R[sjc][2]);
            a[R[sjc][0]] = R[sjc][2];//在a上也进行更改
            sjc++;
        }
        while(sjc>q[i].t){
            sjc--;
            if(l<=R[sjc][0]&&R[sjc][0]<=r)//判断修改是否在该区间内
                Sub(R[sjc][2]),Add(R[sjc][1]);
            a[R[sjc][0]] = R[sjc][1];//在a上也进行更改
        }
        while(l<q[i].l) Sub(a[l++]);
        while(l>q[i].l) Add(a[--l]);
        while(r>q[i].r) Sub(a[r--]);
        while(r<q[i].r) Add(a[++r]);
        ans[q[i].k] = res;
    }
    rep(i,0,cq-1) cout<<ans[i]<<endl;
}