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
//#define INF 0x7fffffff

string s;
const int MAXN = 6e5+5;
bool a[MAXN];
//BBAAABBBBBBB
void solve(){
	cin>>s;
    int n = s.size();
    rep(i,0,n-1){
        if(s[i]=='A') a[i+1]=1;
        else a[i+1]=0; 
    }
    int cnta,cntb,leftb;
    cnta=cntb=leftb=0;
    int xq=0;
    rep(i,1,n){
        while(a[i]==1&&i<=n)cnta++,i++;
        while(a[i]==0&&i<=n)cntb++,i++;
        //cout<<i<<' '<<cnta<<' '<<cntb<<' '<<leftb<<' '<<xq<<endl;
        if(cntb>=cnta){
            xq+=cnta;
            cntb-=cnta;
            cnta=0;
            xq+=cntb/2;
            if(cntb%2) leftb++;
            cnta=cntb=0;//可能剩余一个b在前面
        }
        else{
            xq+=cntb;
            cnta-=cntb;
            cntb=0;
        }
        //cout<<i<<' '<<cnta<<' '<<cntb<<' '<<leftb<<' '<<xq<<endl;
        i--;
    }
    xq+=(leftb/2);
    cout<<n-xq*2<<endl;
}

int main(){
	int z;
	cin>>z;
	while(z--) solve();
}