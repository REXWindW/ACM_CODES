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
string a,b;
void solve(){
    cin>>a>>b;
    int lla = a.size();
    int llb = b.size();
    if(llb>lla){cout<<b<<endl;return;}
    if(llb==lla){
        if(b>a){cout<<b<<endl;return;}
        else{cout<<'1'+b<<endl;return;}
    }
    //排除这种情况后，lla一定是大于llb的
    int cha = lla-llb;
    cout<<string(cha+1,'1')+b<<endl;
}

int main(){
    solve();
}