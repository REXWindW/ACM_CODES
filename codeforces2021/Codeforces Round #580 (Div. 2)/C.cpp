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
int n;
void solve(){
    cin>>n;
    if(n%2==0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<1<<' ';
    rep(i,1,n/2){
        cout<<i*4<<' '<<i*4+1<<' ';
    }
    rep(i,1,n/2){
        cout<<i*4-2<<' '<<i*4-2+1<<' ';
    }
    cout<<2*n<<' ';
    cout<<endl;
}

int main(){
    solve();
}