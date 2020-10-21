#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN=  1e6+5;
int n;
int a[MAXN];
void solve(){
    cin>>n;
    int maxx = 0;
    rep(i,1,n){
        cin>>a[i];
        maxx = max(maxx,a[i]);
    }
    a[0] = a[n+1] = 0x3f3f3f3f;
    rep(i,1,n){
        if(a[i]==maxx)
            if(a[i]>a[i-1]||a[i]>a[i+1]){
                cout<<i<<endl;
                return;
            }
    }
    cout<<-1<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}