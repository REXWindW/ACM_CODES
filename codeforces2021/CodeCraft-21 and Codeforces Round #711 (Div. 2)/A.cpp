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
int n;
bool judge(int nn){
    int tmp = 0;
    int x = nn;
    while(x){
        tmp+=x%10;
        x/=10;
    }
    if(gcd(tmp,nn)>1) return 1;
    return 0;
}
void solve(){
    cin>>n;
    int px = n;
    while(!judge(px)) px++;
    cout<<px<<endl;
}

signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}