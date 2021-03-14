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
#define int ll
int n,m,q;
int a,b,c,d;
int qk[5];

void solve(){
    cin>>n>>m>>q;
    int gcdd = gcd(n,m);
    //cout<<gcdd<<endl;
    qk[1] = n/gcdd;//每个区块有几个
    qk[2] = m/gcdd;//每个区块有几个
    while(q--){
        cin>>a>>b>>c>>d;
        int inn1 = (b-1)/qk[a];
        int inn2 = (d-1)/qk[c];
        //cout<<"inn1"<<inn1<<endl;
        //cout<<"inn2"<<inn2<<endl;
        if(inn1==inn2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}

signed main(){
    solve();
}