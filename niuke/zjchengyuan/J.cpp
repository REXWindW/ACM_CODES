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
int n,k;
const int MAXN = 114514*10;
int a[MAXN],b[MAXN];
void solve(){
    cin>>n>>k;
    rep(i,1,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+1+n);
    int now = k;
    int cnt = 0;
    rep(i,1,n){
        if(a[i]==now){
            now++;
            cnt++;
        }
    }
    rep(i,1,n){
        cout<<max(0,b[i]-cnt);
        if(i!=n) cout<<' ';
    }
    cout<<endl;
}

int main(){solve();
}