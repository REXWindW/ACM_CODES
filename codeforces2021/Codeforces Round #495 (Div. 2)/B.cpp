#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define mkp make_pair
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

const int MAXN = 114514;
int res[MAXN];
vector<pip> a;
int n,m;

void solve(){
    cin>>n;
    rep(i,1,n){
        if(i%2) cout<<0;
        else cout<<1;
    }
    cout<<endl;
}

int main(){
    solve();
}