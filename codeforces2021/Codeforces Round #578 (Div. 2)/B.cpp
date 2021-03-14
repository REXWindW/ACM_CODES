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
int n,m,k;
const int MAXN = 114514;
int h[MAXN];//100
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n) cin>>h[i];
    bool flag = 1;
    rep(i,1,n-1){
        if(h[i]>h[i+1]-k){
            m+=h[i]-max(0,h[i+1]-k);
        }
        else{
            m-=(h[i+1]-k-h[i]);
            if(m<0){
                flag = 0;break;
            }
        }
    }
    if(!flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}