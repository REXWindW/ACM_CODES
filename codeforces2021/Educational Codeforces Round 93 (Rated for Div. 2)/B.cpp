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
#define mkp make_pair
#define ft first
#define sd second
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
string s;
vector<int> vec;
void solve(){
    vec.clear();
    cin>>s;
    int a=0,b=0;//score
    int siz = s.size(),px;
    rep(i,0,siz-1){
        if(s[i]=='0') continue;
        px = i;
        while(px+1<siz&&s[px+1]=='1') px++;
        vec.push_back(px-i+1);
        i = px;
    }
    sort(vec.begin(),vec.end(),greater<int>());
    siz = vec.size();
    rep(i,0,siz-1){
        if(i%2==0) a+=vec[i];
        else b+=vec[i];
    }
    cout<<a<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}