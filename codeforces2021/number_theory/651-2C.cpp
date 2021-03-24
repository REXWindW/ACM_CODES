#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int n;
//奇数a直接赢
//n为偶数且有奇数因子的情况下:
//a使得n变为2^k形式
//b只能取走一个，剩下来一个奇数，只要不是1，a就赢了
bool isprim(int x){
    int sqr = sqrt(x);
    rep(i,2,sqr)
        if(x%i==0) return 0;
    return 1;
}
void solve(){
    cin>>n;
    if(n==1){cout<<"FastestFinger"<<endl;return;}
    if(n%2){cout<<"Ashishgup"<<endl;return;}//odd
    int c2 = 0;
    while(n%2==0){
        n>>=1;c2++;
    }
    if(n==1){
        if(c2==1) cout<<"Ashishgup"<<endl;
        else cout<<"FastestFinger"<<endl;
        return;
    }
    //有奇数除数，我直接拿走!
    if(c2==1){//只有一个2的情况
        if(isprim(n)) cout<<"FastestFinger"<<endl;
        else cout<<"Ashishgup"<<endl;
        return;
    }
    cout<<"Ashishgup"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}