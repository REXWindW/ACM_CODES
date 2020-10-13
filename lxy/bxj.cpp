#include<iostream>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
ll now,maxx,hc;
int n,m;
int main(){
    while(cin>>m){
        cin>>n;
        now = 0;maxx = -(1LL<<62);
        rep(i,1,n){
            cin>>hc;
            if(now<0) now = 0;
            now += hc;
            maxx = max(now,maxx);
        }
        if(maxx>=m) cout<<maxx-m<<endl;
        else cout<<"zltzhdh"<<endl;
    }
}