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
ll pd;

vector<int> vec;
void solve(){
    pd = 1;
    cin>>n;
    int cnt = 0;
    rep(i,1,n-1){
        if(gcd(i,n)==1){
            pd=pd*i%n;
            vec.push_back(i);
            cnt++;
        }
    }
    if(pd==1){
        cout<<vec.size()<<endl;
        int siz = vec.size();
        rep(i,0,siz-1){
            cout<<vec[i]<<' ';
        }
        cout<<endl;
    }
    else{
        cout<<vec.size()-1<<endl;
        int siz = vec.size();
        rep(i,0,siz-1){
            if(vec[i]==pd) continue;
            cout<<vec[i]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    solve();
}