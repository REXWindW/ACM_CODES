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
int siz;
void solve(){
    cin>>s;
    siz = s.size();
    bool flag = 0;
    rep(i,0,siz-1){
        if(s[i]!='a')flag = 1;
    }
    if(!flag){
        cout<<"NO"<<endl;return;
    }
    int l=0,r=siz-1,cl=0,cr=0;
    while(s[l]=='a'){
        l++;
        cl++;
    }
    while(s[r]=='a'){
        r--;
        cr++;
    }
    cout<<"YES"<<endl;
    if(cl>=cr){
        cout<<'a'<<s<<endl;
    }
    else cout<<s<<'a'<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}