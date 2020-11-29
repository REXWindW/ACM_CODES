#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
int a[5];
int maxx;
int lowf,yuzhi;
bool flag[5];
void solve(){
    rep(i,1,4){
        flag[i] = 1;
        cin>>a[i];
        maxx = max(maxx,a[i]);
    }
    cin>>lowf>>yuzhi;
    rep(i,1,4){
        if(maxx-a[i]>yuzhi) flag[i] = 0;
        if(a[i]<lowf) flag[i] = 0;
    }
    int cnt = 0;
    int res;
    rep(i,1,4){
        if(flag[i]==0){cnt++;
        res = i;}
    }
    if(cnt==0){
        cout<<"Normal"<<endl;
    }
    else if(cnt==1){
        cout<<"Warning: please check #"<<res<<"!"<<endl;
    }
    else{
        cout<<"Warning: please check all the tires!"<<endl;
    }
}
int main(){
    solve();
}