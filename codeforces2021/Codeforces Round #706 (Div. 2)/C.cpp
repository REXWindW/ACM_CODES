#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

inline double dis(ll x,ll y){
    return sqrt(x*x+y*y);
}

int n,x,y;
vector<int> g;//工
vector<int> k;//矿

void solve(){
    g.clear();k.clear();
    scanf("%d",&n);
    rep(i,1,2*n){
        scanf("%d%d",&x,&y);
        if(x==0) g.push_back(abs(y));
        else if(y==0) k.push_back(abs(x));//只用管绝对值即可
    }
    double res = 0;
    sort(g.begin(),g.end());
    sort(k.begin(),k.end());
    rep(i,0,n-1){
        res += dis(g[i],k[i]);
    }
    printf("%.12lf\n",res);
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}