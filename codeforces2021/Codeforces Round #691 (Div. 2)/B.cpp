#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
int n;
void solve(){
    cin>>n;
    int g = (n+1)/2*2+1;
    int res;
    if(n%2){
        res = ((g+1)/2 * (g/2))*2;
    }
    else{
        res = ((g+1)/2)*((g+1)/2);
    }
    cout<<res<<endl;
}

int main(){
    solve();
}