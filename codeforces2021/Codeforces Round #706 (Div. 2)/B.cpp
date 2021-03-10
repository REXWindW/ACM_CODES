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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int a[MAXN];
int n,k;
void solve(){
    cin>>n>>k;
    rep(i,0,n-1) cin>>a[i];
    if(k==0){cout<<n<<endl;return;}
    sort(a,a+n);
    int px = -1;
    rep(i,0,n-1){
        if(a[i]!=i){px = i;break;}
    }
    if(px==-1){
        cout<<n+k<<endl;
        return;
    }
    //px就是mex
    int nw = (px+a[n-1]+1)/2;//找到mex和max/2的值
    bool flag = 0;
    //cout<<"nw"<<nw<<endl;
    rep(i,0,n-1){
        if(a[i]==nw){flag = 1;break;}
    }
    if(flag) cout<<n<<endl;
    else cout<<n+1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}