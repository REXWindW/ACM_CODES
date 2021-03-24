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
int n;
const int MAXN = 114514;
string s;
int a[MAXN];
//bool vis[MAXN];
//出现第一个1之后的所有0都擦得只剩一个，然后再消去1
void solve(){
    cin>>n;
    cin>>s;
    rep(i,1,n) a[i] = s[i-1]-'0';
    int f1=INF,l0=-1;
    rep(i,1,n){
        //找第一个1和最后一个0
        if(a[i]==0) l0 = max(i,l0);
        if(a[i]==1) f1 = min(i,f1);
    }
    if(f1>l0){
        cout<<s<<endl;
        return;
    }
    rep(i,1,f1-1) cout<<0;
    cout<<0;//l0
    rep(i,l0+1,n) cout<<1;
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}