#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int a[114514];
int main(){
    rep(i,0,23) cin>>a[i];
    int hc;
    while(cin>>hc){
        if(hc<0||hc>23)break;
        cout<<a[hc]<<' ';
        if(a[hc]>50) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}