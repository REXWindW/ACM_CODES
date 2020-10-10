#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define INF 0x3f3f3f3f
#define cendl printf("\n")
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
string a,b;
const int MAXN = 1e5+5;
int aa[MAXN];
int bb[MAXN];
int cc[MAXN];
void solve(){
    vector<int> res;
    vector<int> res2;
    res2.push_back(0);
    cin>>a>>b;
    int siz = a.size();
    rep(i,1,siz){
        aa[i] = a[i-1]-'0';
        bb[i] = b[i-1]-'0';
        cc[i] = 0;
    } 
    int now = 0;
    int now2 = 0;
    rep(i,1,siz){
        if((aa[i]+now)%2!=bb[i]){res.push_back(i);now=now+1%2;}
        if((cc[i]+now2)%2!=bb[i]){res2.push_back(i);now2=now2+1%2;}
    }
    if(res.size()<res2.size()){
        siz = res.size();
        rep(i,0,siz-1){
            cout<<res[i];
            if(i!=siz-1) cout<<' ';
        }
        cout<<endl;
    }
    else{
        siz = res2.size();
        rep(i,0,siz-1){
            cout<<res2[i];
            if(i!=siz-1) cout<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int z;
    cin>>z;
    while(z--)solve();
}