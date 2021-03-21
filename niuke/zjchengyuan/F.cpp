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
string s;
int n;
bool flag;
void dfs(int l,int r,int dl){
    if(dl>2) return;
    if(flag) return;
    if(l>=r){
        flag = 1;return;
    }
    if(s[l]!=s[r]){
        //删左
        dfs(l+1,r,dl+1);
        //删右
        dfs(l,r-1,dl+1);
        //都删
        dfs(l+1,r-1,dl+2);
    }
    else{
        dfs(l+1,r-1,dl);
    }
}
void solve(){
    flag = 0;
    cin>>n;
    cin>>s;
    dfs(0,n-1,0);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}