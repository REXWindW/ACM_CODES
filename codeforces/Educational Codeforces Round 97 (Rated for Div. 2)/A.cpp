#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
void solve(){
    int l,r;
    cin>>l>>r;
    if(r+1<=l*2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}