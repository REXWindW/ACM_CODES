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
const int MAXN = 114514;
int a[MAXN];
char hc;
int n;
int c[3];
void solve(){
    cin>>n;
    c[0]=c[1]=0;
    rep(i,1,n){
        cin>>hc;
        a[i] = (hc=='T');//TMT=101
        c[a[i]]++;
    }
    if(c[1]!=c[0]*2){
        cout<<"NO"<<endl;
        return;
    }
    c[0]=c[1]=0;
    rep(i,1,n){
        c[a[i]]++;
        if(c[0]>c[1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    c[0]=c[1]=0;
    repb(i,n,1){
        c[a[i]]++;
        if(c[0]>c[1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
//从后往前，如果某一位置M数量大于T数量则不可以
//从前往后，如果某一位置M大于T则不可