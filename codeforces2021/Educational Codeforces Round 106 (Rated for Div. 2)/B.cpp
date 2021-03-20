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
//找到一个位置，前面出现的1都不相邻，后面出现的0都不相邻
string s;
const int MAXN = 1145;
int a[MAXN];
void solve(){
    cin>>s;
    int n = s.size();
    rep(i,1,n){
        a[i] = s[i-1]-'0';
    }
    int pre = -1;
    int px;
    for(px=1;px<=n;px++){
        if(a[px]==1){
            if(px-pre==1)//not ok
                break;
            pre = px;
        }
    }
    int py;
    int pry = n+2;
    for(py=n;py>=1;py--){
        if(a[py]==0){
            if(pry-py==1)
                break;
            pry = py;
        }
    }
    //cout<<"x"<<px<<"y"<<py<<endl;
    if(px>=py) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}