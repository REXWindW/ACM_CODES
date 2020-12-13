#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f

const int MAXN = 114514;
int a[MAXN],b[MAXN];
int n;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;//val,na,nb
#define ft first
#define sd second
#define mkp make_pair
priority_queue<pip,vector<pip>,greater<pip>> q;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i]; 
    rep(i,1,n) cin>>b[i];
    sort(a+1,a+n+1,less<int>());
    sort(b+1,b+n+1,less<int>());
    rep(i,1,n)
        q.push(mkp(a[i]+b[1],mkp(i,1)));
    rep(i,1,n){
        pip now = q.top();
        cout<<now.ft<<' ';
        q.pop();
        if((now.sd).sd<n)
            q.push(mkp(a[now.sd.ft]+b[now.sd.sd+1],mkp(now.sd.ft,now.sd.sd+1)));
    }
    cout<<endl;
}

int main(){
    solve();
}