#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
int n;
string s;
void solve(){
    cin>>n;
    cin>>s;
    bool flag = 0;
    if(s.substr(0,4)=="2020"||s.substr(n-4,4)=="2020")
        flag=1;
    else if(s.substr(0,2)=="20"&&s.substr(n-2,2)=="20")
        flag=1;
    else if(s.substr(0,1)=="2"&&s.substr(n-3,3)=="020")
        flag=1;
    else if(s.substr(0,3)=="202"&&s.substr(n-1,1)=="0")
        flag=1;
    if(flag )cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}