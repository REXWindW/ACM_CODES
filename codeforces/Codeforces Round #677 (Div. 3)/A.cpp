#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n,x;
int sum[10];
void solve(){
    cin>>x;
    int num = x%10;
    int cnt = 0;
    while(x){
        x/=10;
        cnt++;
    }
    int res = (num-1)*sum[4]+sum[cnt];
    cout<<res<<endl;
}

int main(){
    sum[0] = 0;
    rep(i,1,9)
        sum[i] = sum[i-1]+i;
    int z;
    cin>>z;
    while(z--) solve();
}