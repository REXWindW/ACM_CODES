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
const int MAXN = 114514;
int a[MAXN],nxt[MAXN];

void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    nxt[n]=-1;//记录之后最近一次出现两次以上的数字
    repb(i,n-1,1){
        if(a[i]==a[i+1]) nxt[i]=a[i];
        else nxt[i]=nxt[i+1];
    }
    int top[2];//两个栈的栈顶元素
    top[0]=top[1]=-1;
    int res=0;
    rep(i,1,n){
        if(a[i]==a[i+1]){//重复长段,放哪儿都一样
            if(top[0]!=a[i]) res++;
            top[0]=a[i];
        }
        else{//重复长段末尾/单个字符
            if(top[0]==a[i]) res+=(top[1]!=a[i]),top[1]=a[i];
            else if(top[1]==a[i]) res+=(top[0]!=a[i]),top[0]=a[i];
            else{
                if(top[0]==nxt[i]) res++,top[0]=a[i];
                else res++,top[1]=a[i];
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    solve();
}