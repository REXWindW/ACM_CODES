#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 1e5+5;
int a[MAXN];//存原数字
int cfji[MAXN];
int cfou[MAXN];
int n,k;
int solve(){
    cfji[0]=cfou[0] = 0;
    rep(i,1,n){
        cin>>a[i];
        cfji[i] = cfou[i] = 0;
    }
    int jiou = k%2;
    rep(i,1,n){
        if(i%2==jiou){
             
        }
    }
}
int main(){
    while(cin>>n>>k;)
}