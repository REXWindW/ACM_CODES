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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int a[MAXN],b[MAXN];
int n,minn;
void solve(){
    cin>>n;
    minn = INF;
    rep(i,1,n){
        cin>>a[i];
        b[i] = a[i];
        minn = min(a[i],minn);
    }
    //拿这个最小的用来做中间交换，所有可以被它整除的都可以和他交换！
    //有些不行的数字，要求这些数字分割的段数中间的数字数量正确
    //比如3 6 8 9 10，8和10中间怎么变都只可能有一个数字
    //先检查这些特殊数字(不能被minn整除的)顺序是否正确，再检查间隔是否可以
    sort(b+1,b+1+n);
    bool flag = 1;
    rep(i,1,n){
        if(b[i]%minn){
            if(a[i]!=b[i]){
                flag = 0;break;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}