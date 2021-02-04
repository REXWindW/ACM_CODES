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
const int MAXN = 2e5+5;
int n;
typedef pair<int,int> pii;
#define ft first
#define sd second
pii a[MAXN];
//树状数组板子
int d[MAXN];
int lowbit(int x){return x&-x;}
int sum(int i){
    int ret = 0;
    while(i>0){
        ret+=d[i];
        i-=lowbit(i);
    }
    return ret;
}
void update(int i,int val){
    while(i<=n){
        d[i]+=val;
        i+=lowbit(i);
    }
}
//
void solve(){
    cin>>n;
    rep(i,1,n){
        d[i]=0;
        cin>>a[i].ft>>a[i].sd;
    }
    sort(a+1,a+1+n);
    ll res = 0;
    rep(i,1,n){
        //cout<<sum(n)-sum(a[i].sd);
        res+=sum(n)-sum(a[i].sd);
        update(a[i].sd,1);
    }
    if(res%2) cout<<-1<<endl;
    else cout<<1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}