#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
#define int ll
const int MAXN = 2*114514;
int n;
int a[MAXN];
ll jc[MAXN];
const ll med = 1e9+7;
void init(){
    jc[0] = 1;
    rep(i,1,200001){
        jc[i] = jc[i-1]*i%med;
    }
}
inline void solve(){
    cin>>n;
    cin>>a[1];
    int tot = a[1];//tot为所有数字的与！
    //这个与的数字一定要存在，而且第一位和最后一位都要是它才行
    rep(i,2,n){
        cin>>a[i];
        tot&=a[i];
    }
    ll cnt = 0;
    rep(i,1,n){
        if(a[i]==tot) cnt++;
    }
    if(cnt<2){
        cout<<0<<endl;
        return;
    }
    //这样一来cnt至少有两个
    ll res = jc[n-2];
    res=(res*(cnt)%med)*(cnt-1)%med;
    cout<<res<<endl;
}

signed main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}