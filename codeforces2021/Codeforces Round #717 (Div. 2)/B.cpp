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
ll n;
//至多分为三段
const int MAXN = 114514;
ll a[MAXN],sum[MAXN];
void solve(){
    cin>>n;
    sum[0] = 0;
    rep(i,1,n){
        cin>>a[i];
        sum[i] = sum[i-1]^a[i];//xor sum
    }
    if(sum[n]==0){//two elements
        cout<<"YES"<<endl;
        return;
    }
    if(n==2){
        cout<<"NO"<<endl;
        return;
    }
    //three elements
    rep(i,1,n){
        if(sum[i]==sum[n]){//三个的情况，第一个一定等于异或和
            rep(j,i+1,n){
                if(sum[j]==0){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}