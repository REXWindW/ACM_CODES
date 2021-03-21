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
string s;
int n;
int cl,cr;
void solve(){
    cin>>s;
    n = s.size();
    rep(i,0,2){
        cl=cr = 0;
        bool flag = 1;
        rep(j,0,n-1){
            if(s[j]-'A'==i) cl++;
            else cr++;
            if(cl<cr){flag=0;break;}
        }
        if(flag&&cl==cr){
            cout<<"YES"<<endl;return;
        }
    }
    rep(i,0,2){
        cl=cr = 0;
        bool flag = 1;
        rep(j,0,n-1){
            if(s[j]-'A'==i) cr++;
            else cl++;
            if(cl<cr){flag=0;break;}
        }
        if(flag&&cl==cr){
            cout<<"YES"<<endl;return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}