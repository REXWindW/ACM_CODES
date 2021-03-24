#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
string s,t;
void solve(){
    cin>>s>>t;
    int siz = s.size();
    int tiz = t.size();
    int px;
    int cnt,cntp;
    int i;
    bool flag = 1;
    for(i=0,px=0;i<siz&&px<tiz;i++,px++){
        cnt = 1;
        while(i+1<siz&&s[i+1]==s[i]){
            i++;cnt++;
        }
        if(t[px]!=s[i]){
            flag=0;
            break;
        }
        cntp = 1;
        while(px+1<tiz&&t[px+1]==s[i]){
            px++;cntp++;
        }
        if(cntp<cnt){
            flag=0;break;
        }
    }
    if(i==siz&&px==tiz&&flag){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}