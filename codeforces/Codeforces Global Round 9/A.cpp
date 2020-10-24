#include<iostream>
using namespace std;
int n;
int hc;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>hc;
        if(i%2) cout<<abs(hc)<<' ';
        else cout<<-abs(hc)<<' ';
    }
    cout<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}