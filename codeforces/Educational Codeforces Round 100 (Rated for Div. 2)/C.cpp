#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define mkp make_pair
#define ft first
#define sd second
const ll LINF = 1ll<<58;
int n;
const int MAXN = 114514;
typedef pair<ll,ll> pll;
pll a[MAXN];
//入栈和栈顶元素进行比较，判断栈顶的目标是否完成：其实和上一个比就完事了
pll now;//当前真实执行的任务
ll pos;
bool tonghao(ll x,ll y){
    return x*y>=0;
}
void solve(){
    pos = 0;
    cin>>n;
    int cnt = 0;//有效指令数
    cin>>a[1].ft>>a[1].sd;
    now = a[1];
    rep(i,2,n+1){
        if(i<=n)cin>>a[i].ft>>a[i].sd;//ft时间,sd目标
        else a[i]=mkp(LINF,LINF);//用来判断最后一条指令
        //检查上一个指令是否有效
        if(tonghao(a[i-1].sd-pos,now.sd-pos)&&abs(a[i-1].sd-pos)<=abs(now.sd-pos)){
            if(a[i].ft-now.ft>=abs(a[i-1].sd-pos)){
                cnt++;
                //cout<<"mission "<<i<<" succeed"<<endl;
            }
        }
        if(a[i].ft-now.ft>=abs(now.sd-pos)){//now任务已经执行完成的情况
            pos = now.sd;
            now = a[i];//更新任务
        }
        else{
            if(now.sd>=pos) pos = min(now.sd,pos+(a[i].ft-now.ft));
            else pos = max(now.sd,pos-(a[i].ft-now.ft));
            now.ft = a[i].ft;
        }
    }
    //cout<<"res"<<cnt<<endl;
    cout<<cnt<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}