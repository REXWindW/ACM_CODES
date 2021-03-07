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
const int MAXN = 114514; 
int x,y;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n;
string s;
int a[MAXN];
int sum[10];
void solve(){
    rep(i,0,3) sum[i]=0;
    cin>>x>>y;
    cin>>s;
    n = s.size();
    rep(i,0,n-1){
        if(s[i]=='U')a[i]=0;
        else if(s[i]=='D')a[i]=1;
        else if(s[i]=='R')a[i]=2;
        else a[i]=3;
        sum[a[i]]++; 
    }
    bool flag = 1;
    if(x>=0){
        if(sum[2]<x) flag = 0;
    }
    else{
        if(sum[3]<-x)flag = 0;
    }
    if(y>=0){
        if(sum[0]<y) flag = 0;
    }
    else{
        if(sum[1]<-y) flag = 0;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}