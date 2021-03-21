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
int a[12]={0,12,14,16,19,21,24,30,10000};
string s[12]={"Newbie","Pupil","Specialist","Expert","Candidate Master","Master","Grandmaster","Legendary Grandmaster"};
int x,y;
void solve(){
    cin>>x>>y;
    rep(i,0,8){
        if(a[i]*100>x){x=i-1;break;}
    }
    rep(i,0,8){
        if(a[i]*100>y){y=i-1;break;}
    }
    if(x==y) cout<<"NO"<<endl;
    else cout<<s[x]<<" to "<<s[y]<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}