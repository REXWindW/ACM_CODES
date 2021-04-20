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
const int MAXN = 114514;
int cnt[3];
int n;
void solve(){
    cin>>n;
    int hc;
    cnt[0]=cnt[1] = 0;
    rep(i,1,n){
        cin>>hc;
        cnt[hc]++;
    }
    int num = cnt[0]>=cnt[1]?0:1;
    if(num==1&&cnt[1]&1) cnt[1]--;
    cout<<cnt[num]<<endl;
    rep(i,1,cnt[num]){
        cout<<num<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}