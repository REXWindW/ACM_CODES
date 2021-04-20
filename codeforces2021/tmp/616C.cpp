#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,m,k;
const int MAXN = 3888;
int a[MAXN];
void solve(){
    cin>>n>>k>>m;
    m = min(m,k-1);//只有前k-1个脑控有效
    rep(i,1,n){
        cin>>a[i];
    }
    int lb,rb;//脑控的m个人拿完了之后我可以拿到的位置
    int rt = k-m-1;//中间还剩多少没被脑控的人
    //想了一个n方的算法
    int maxx = -1;
    rep(tl,0,m){//枚举我脑控的几个人从左边拿了l个
        int tr = m-tl;//右边拿了几个
        lb = tl,rb = n-tr+1;
        //再枚举有哪些我可能拿到的位置
        int minn = INF;
        rep(i,0,rt){
            minn = min(minn,max(a[lb+i+1],a[rb-(rt-i)-1]));
        }
        maxx = max(maxx,minn);
    }
    cout<<maxx<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}