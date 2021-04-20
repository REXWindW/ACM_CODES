#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
string s;
int q,l,r;
const int MAXN = 114514*2;
char a[MAXN];
inline void solve(){
    cin>>s;
    int n = s.size();
    rep(i,1,n){
        a[i] = s[i-1];
    }
    cin>>q;
    while(q--){
        cin>>l>>r;
        if(l==r){//单个字母的情况
            cout<<"YES"<<endl;
            return;
        }
        //abca
        //首位两个字母相同不行
        //只要开头和结尾字母不同
        //策略：把开头字母和结尾字母调换构造

    }
}

int main(){
    solve();
}