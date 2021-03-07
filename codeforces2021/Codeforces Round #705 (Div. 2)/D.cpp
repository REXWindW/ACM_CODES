#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 2e5+5;
bool prim[MAXN];
vector<int> primm;
map<int> mp[MAXN];//第i个位置有几个质数j
map<int> cp[MAXN];//质数j在几个位置出现了i次以上？
void ass(){
    rep(i,2,MAXN-5){m 
        if(prim[i]) continue;
        primm.push_back(i);
        for(int j=i*2;j<=MAXN-5;j+=i)
            prim[j]=1;
    }
    cout<<primm.size()<<endl;
}

void solve(){
    
}

int main(){
    ass();
    int z;
    cin>>z;
    while(z--) solve();
}