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
const int MAXN = 114514;
int a[MAXN];
int n;
int top;
void push(int x){
    a[++top] = x;
}
void solve(){
    cin>>a[1]>>a[2]>>n;
    top = 2;
    int tmp;
    int now = 1;
    while(top<n){
        tmp = a[now]*a[now+1];
        now++;
        if(tmp>10) push(tmp/10);
        push(tmp%10);
    }
    rep(i,1,n){
        cout<<a[i];
        if(i!=n)cout<<' ';
    }
    cout<<endl;
}
int main(){
    solve();
}