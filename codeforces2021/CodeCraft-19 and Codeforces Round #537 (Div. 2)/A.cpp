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
char c[5]={'a','e','i','o','u'};
int n;
string s,t;
bool isy(char ch){
    rep(i,0,4){
        if(c[i]==ch){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>s>>t;
    if(s.size()!=t.size()){
        cout<<"NO"<<endl;
        return;
    }
    int siz = s.size();
    rep(i,0,siz){
        if(isy(s[i])!=isy(t[i])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    solve();
}