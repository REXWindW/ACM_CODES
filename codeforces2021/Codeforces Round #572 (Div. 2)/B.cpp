#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int a[MAXN];
int n;
deque<int> q;

void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    if(a[2]+a[3]<=a[1]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    rep(i,1,n){
        if(i%2) q.push_front(a[i]);
        else q.push_back(a[i]);
    }
    rep(i,1,n){
        cout<<q.front()<<' ';
        q.pop_front();
    }
    cout<<endl;
}

int main(){
    solve();
}