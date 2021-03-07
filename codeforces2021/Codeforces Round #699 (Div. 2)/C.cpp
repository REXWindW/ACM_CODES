#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//看最后一个c, 找到对应要求的b位置
//这个位置就当作处理位，最后用末尾c来填充

const int MAXN = 114514;
int n,m;
int a[MAXN],b[MAXN],c[MAXN];
queue<int> q[MAXN];
int dl;//处理位(垃圾堆)
int res[MAXN];//存储结果
void clr(queue<int> &qq){
    queue<int> tmp;
    swap(tmp,qq);
}
void solve(){
    dl = 0;
    cin>>n>>m;
    rep(i,1,n){cin>>a[i];clr(q[i]);}
    rep(i,1,n) cin>>b[i];
    rep(i,1,m) cin>>c[i];
    rep(i,1,n)
        if(a[i]!=b[i]) q[b[i]].push(i);//i位置待处理
    if(q[c[m]].empty()){
        rep(i,1,n){
            if(b[i]==c[m]){//这种先破坏掉当处理位
                dl = i;break;
            }
        }
        if(!dl){
            cout<<"NO"<<endl;return;
        }
    }
    else{
        dl = q[c[m]].front();
        q[c[m]].pop();//从集合中取出
    }
    rep(i,1,m-1){
        if(!q[c[i]].empty()){
            res[i]=q[c[i]].front();
            q[c[i]].pop();
        }
        else res[i]=dl;
    }
    res[m]=dl;
    bool flag = 1;
    rep(i,1,n){
        if(!q[i].empty()){
            flag = 0;break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        rep(i,1,m) cout<<res[i]<<' ';
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}