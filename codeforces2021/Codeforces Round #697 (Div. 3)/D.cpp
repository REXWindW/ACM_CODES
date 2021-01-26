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
typedef pair<int,int> pii;//用pair来存app的信息,first存a,second存b
#define ft first
#define sd second
const int MAXN = 114514*2;
pii a[MAXN];
bool cmp(pii a,pii b){//自定义地比较函数，性价比高地排在前面
    if((double)a.ft/a.sd>(double)b.ft/b.sd) return 1;
    else if((double)a.ft/a.sd==(double)b.ft/b.sd)
        return a.sd<b.sd;
    return 0;
}
int n,m;
void solve(){
    cin>>n>>m;
    rep(i,1,n)
        cin>>a[i].ft;
    rep(i,1,n)
        cin>>a[i].sd;
    sort(a+1,a+1+n,cmp);
    int nowm = 0;
    int cost = 0;
    int pre1=0,pre2=0;//上次选择的
    rep(i,1,n){
        if(nowm>=m&&pre2&&nowm-a[pre2].ft+a[i].ft>=m&&a[i].sd==1){
            cost--;
            nowm=INF;
            break;//处理完这种特殊情况后可以直接退出了,因为消耗不可能更小了
        }//第二种特殊情况
        else if(nowm<m&&pre1&&nowm-a[pre1].ft+a[i].ft>=m){
            cost++;
            nowm=INF;
            break;
        }//第一种特殊情况
        else if(nowm<m){
            if(a[i].sd==1)pre1 = i;
            else if(a[i].sd==2) pre2 = i;
            cost+=a[i].sd;
            nowm+=a[i].ft;
        }
    }
    if(nowm<m) cout<<-1<<endl;
    else cout<<cost<<endl;
}
int main(){
    int z;
    cin>>z;
    while(z--) solve();
}