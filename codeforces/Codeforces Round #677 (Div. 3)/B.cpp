#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

void solve(){
    int hc,n;
    cin>>n;
    int sum=0,cnt=0;
    bool flag = 0;
    rep(i,1,n){
        cin>>hc;
        if(hc==1){
            flag = 1;
            sum += cnt;
            cnt = 0;
        }
        else if(flag) cnt++;
    }
    cout<<sum<<endl;

}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}