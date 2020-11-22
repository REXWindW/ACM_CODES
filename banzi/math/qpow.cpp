#include<iostream>
using namespace std;
#define ll long long
const ll med = 1e9+7;
ll qpow(ll d,ll mi){//底，幂
    ll res = 1;
    while(mi){
        if(mi%2) res=res*d%med;
        d = d*d%med;
        mi/=2;
    }
    return res;
}
int main(){
    ll d,mi;
    cin>>d>>mi;
    cout<<qpow(d,mi);
}