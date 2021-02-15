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
string s;
void solve(){
    cin>>s;
    int siz = s.size();
    rep(i,0,siz-1){
        if(i%2==0){
            if(s[i]=='a') cout<<'b';
            else cout<<'a';
        }
        else{
            if(s[i]=='z') cout<<'y';
            else cout<<'z';
        }
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}