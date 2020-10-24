#include<iostream>
using namespace std;
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
int n;
void solve(){
    cin>>n;
    int zs = n/4;
    int ys = n%4;
    repb(i,n,1){
        if(i>zs+1) cout<<9;
        else if(i==zs+1){
            if(ys==0) cout<<9;
            else cout<<8;
        }
        else{
            cout<<8;
        }
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}