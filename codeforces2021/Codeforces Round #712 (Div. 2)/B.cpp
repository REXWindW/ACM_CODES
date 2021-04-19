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
const int MAXN = 3*114514;
int a[MAXN],b[MAXN];
int cnt[MAXN];
int n;
void solve(){
    cnt[0] = 0;
    cin>>n;
    char hc;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
        cnt[i] = cnt[i-1]+a[i];
    }
    rep(i,1,n){
        cin>>hc;
        b[i] = hc-'0';
    }
    bool flag = 1;
    rep(i,1,n-1){
        if((a[i]!=a[i+1]&&b[i]==b[i+1])||(a[i]==a[i+1]&&b[i]!=b[i+1])){
            if(cnt[i]*2==i){
                //meiguanxi
            }
            else{flag=0;break;}
        }
    }
    if(!flag){cout<<"NO"<<endl;return;}
    if(a[n]!=b[n]&&cnt[n]*2!=n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}