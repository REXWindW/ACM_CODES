#include<iostream>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
ll now,maxx,hc;
int n;
int main(){
    while(cin>>n){
        now = 0;maxx = -(1LL<<62);
    	cout<<maxx<<endl;
        rep(i,1,n){
            cin>>hc;
            if(now<0) now = 0;
            now += hc;
            maxx = max(now,maxx);
        }
        cout<<maxx<<endl;
    }
}