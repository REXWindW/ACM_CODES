#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x7fffffff
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//因为数据范围比较小所以直接模拟
const int MAXN = 114;
int a[MAXN];
int n,k;
int res;
void solve(){
    a[0]=INF;
    cin>>n>>k;
    a[n+1]=-1;
    a[n+2]=INF;
    rep(i,1,n)
        cin>>a[i];
    rep(j,1,k){
        rep(i,1,n+1){
            if(a[i]<a[i+1]){
                res = i;//停再此处
                a[i]++;break;
            }
        }
        if(res==n+1){res=-1;break;}
    }
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}