#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

const int MAXN = 1e5+5;
vector<int>vec;
int n,k;
string a;
int res;
int head,tail;
void solve(){
    cin>>n>>k;
    cin>>a;
    res = 0;
    bool flag = 0;
    rep(i,0,n-1){
        if(a[i]=='L')flag = 0;
        else{
            if(flag) res+=2;
            else res+=1;
            flag = 1;
        }
    }
    head = tail = 0;
    int cnt = 0;
    int st = 0;
    while(a[st]=='L') st++;
    head = st;//开头有几个连续L
    rep(i,st,n-1){
        if(a[i]=='W') continue;
        cnt =  0;
        while(i<n&&a[i]=='L') cnt++;
        if(i==n){
            tail = cnt;
        }
        else vec.push_back(cnt);
    }
    sort(vec.begin(),vec.end());
    int siz = vec.size();
    rep(i,0,siz-1){
        
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}