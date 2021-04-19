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
#define int ll
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n,m;
int cnt[214514][14];
const int med = 1e9+7;
inline void solve(){
    rep(i,0,9) cnt[0][i] = 0;
    cin>>n>>m;
    while(n){
        cnt[0][n%10]++;
        n/=10;
    }
    rep(i,0,m-1){
        rep(j,0,9){
            if(j==9){
                cnt[i+1][0]=cnt[i][9]%med;
                cnt[i+1][1]+=cnt[i][9];
                cnt[i+1][1]%=med;
            }
            else{
                cnt[i+1][(j+1)%10] = cnt[i][j]%med;
            }
        }
    }
    ll res = 0;
    rep(i,0,9) {res+=cnt[m][i];res%=med;}
    cout<<res<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}