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
const int med = 1e9+7;
const int MAXN = 2e6+5;
ll cnt[MAXN];
bool top[MAXN];//顶点是否被使用

void init(){
    rep(i,3,MAXN-5){
        cnt[i] = 2*cnt[i-2]+cnt[i-1];
        if(top[i-1]==0&&top[i-2]==0){
            top[i] = 1;
            cnt[i]++;
        }
        cnt[i]%=med;
    }
}
int n;
void solve(){
    cin>>n;
    cout<<cnt[n]*4%med<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}