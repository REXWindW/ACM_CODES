#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<random>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 1e3;
mt19937 rnd(233);
int main(){
    freopen("F_in.txt","w",stdout);
    rep(i,1,100){
        cout<<i*30<<' '<<MAXN+rnd()%MAXN<<endl;
    }
}