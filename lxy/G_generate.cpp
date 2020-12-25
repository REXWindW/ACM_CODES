#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
mt19937 rnd(233);
int n,m;
int main(){
    cin>>n>>m;
    rep(i,1,n){
        rep(j,1,m){
            int dd = rnd()%10;
            if(dd==0) cout<<'X';
            else if(dd%2) cout<<'@';
            else cout<<'#';
        }
        cout<<endl;
    }
}