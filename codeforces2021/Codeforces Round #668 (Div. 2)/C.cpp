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
string s;
const int MAXN = 114514*3;
int a[MAXN];
void solve(){
    cin>>n>>k;
    cin>>s;
    rep(i,0,k-1) a[i] = 0;
    rep(i,0,n-1){
        if(s[i]=='1') a[i%k] = 1;
        if(s[i]=='0') a[i%k] = -1;
    }
    int cnt[2]={0};
    rep(i,0,k-1){
        if(a[i]==-1) cnt[0]++;
        if(a[i]==1) cnt[1]++;
    }
    int rest = k-cnt[0]-cnt[1];
    if(max(cnt[0],cnt[1])-min(cnt[0],cnt[1])>rest){
        cout<<"NO"<<endl;
        return;
    }
    rep(i,0,n-1){
        if(s[i]=='?') continue;
        if(s[i]=='1'&&a[i%k]==-1){
            cout<<"NO"<<endl;
            return;
        }
        if(s[i]=='0'&&a[i%k]==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}