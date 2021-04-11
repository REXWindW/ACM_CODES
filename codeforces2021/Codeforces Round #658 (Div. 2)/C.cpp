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
int a[MAXN],b[MAXN];
int n;
vector<int> vec;
void solve(){
    vec.clear();
    cin>>n;
    char hc;
    rep(i,1,n){
        cin>>hc;
        a[i] = hc-'0';
    }
    rep(i,1,n){
        cin>>hc;
        b[i] = hc-'0';
    }
    rep(i,1,n-1){
        if(a[i+1]!=a[i]){
            vec.push_back(i);
        }
    }
    if(a[n]==1) vec.push_back(n);
    //至此，a全部变成0
    int now = 0;
    repb(i,n,1){
        if(b[i]!=now){
            vec.push_back(i);
            now = now^1;
        }
    }
    int siz = vec.size();
    cout<<siz<<' ';
    rep(i,0,siz-1){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}