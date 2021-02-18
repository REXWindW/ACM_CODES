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
int x;
void solve(){
    cin>>x;
    int a,b,c;
    a = 1,b = 1,c = x-a-b;
    if(c%3==0){
        c--,b++;
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}

int main(){
    solve();
}