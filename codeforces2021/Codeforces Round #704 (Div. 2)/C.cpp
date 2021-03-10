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

int n,m;
string s,t;
const int MAXN = 114514*2;
int z[MAXN],f[MAXN];

void solve(){
    cin>>n>>m;
    cin>>s>>t;
    //正着扫
    int px = 0;
    rep(i,0,m-1){
        while(px<n&&s[px]!=t[i]) px++;
        z[i]=px;
        px++;
    }
    //反着来
    px = n-1;
    repb(i,m-1,0){
        while(px>=0&&s[px]!=t[i]) px--;
        f[i]=px;
        px--;
    }
    int res = -INF;
    //算结果
    rep(i,1,m-1){
        res = max(res,f[i]-z[i-1]);
    }
    cout<<res<<endl;
}

int main(){solve();
}