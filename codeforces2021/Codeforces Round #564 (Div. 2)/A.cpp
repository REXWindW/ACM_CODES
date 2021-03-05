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
int n,a,b,x,y;
void solve(){
    cin>>n>>a>>x>>b>>y;
    if(a==b){
        cout<<"YES"<<endl;
        return;
    }
    while(1){
        a = a%n+1;
        b = (b-2+n)%n+1;
        if(a==b){
            cout<<"YES"<<endl;
            return;
        }    
        if(a==x||b==y) break; 
    }
    cout<<"NO"<<endl;
}

int main(){
    solve();
}