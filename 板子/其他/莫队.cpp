#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
const int MAXN = 5e4+5;
int cnt[MAXN];//记录数字在区间[l,r]内出现的次数
int pos[MAXN],a[MAXN];
ll ans[MAXN];
int n,m,k,res;
struct Q{
    int l,r,k;//k记录原来的编号
    friend bool operator < (Q x,Q y){//同一个分块内r小的排前面;不同分块则按分块靠前的
        return pos[x.l]==pos[y.l]?x.r<y.r:pos[x.l]<pos[y.l];
        //return (pos[a.l]^pos[b.l])?pos[a.l]<pos[b.l]:((pos[a.l]&1)?a.r<b.r:a.r>b.r);
        //这条第一个和==是一样的,后面的是对于左端点在同一奇数块的区间，右端点按升序排列，反之降序
    }
}q[MAXN];

void Add(int pos){
    res -= cnt[a[pos]]*cnt[a[pos]];
    cnt[a[pos]]++;
    res += cnt[a[pos]]*cnt[a[pos]];
}
void Sub(int pos){
    res -= cnt[a[pos]]*cnt[a[pos]];
    cnt[a[pos]]--;
    res += cnt[a[pos]]*cnt[a[pos]];
}
int main(){
    cin>>n>>m>>k;//k为数字范围
    memset(cnt,0,sizeof(cnt));
    int siz = sqrt(k);//每个分块的大小
    rep(i,1,n){
        cin>>a[i];
        pos[i] = i/siz;//分块
    }
    rep(i,1,m){
        cin>>q[i].l>>q[i].r;
        q[i].k = i;//记录原来的编号,用于打乱顺序后的还原
    }
    sort(q+1,q+1+m);
    res = 0;//初始化res
    int l = 1,r = 0;//当前知道的区间
    //因为是闭区间,如果是[1,1]的话则一开始就包含一个元素了
    rep(i,1,m){//莫队的核心,注意加减的顺序
        while(q[i].l<l) Add(--l);
        while(q[i].l>l) Sub(l++);
        while(q[i].r<r) Sub(r--);
        while(q[i].r>r) Add(++r);
        ans[q[i].k] = res;
    }
    rep(i,1,m) cout<<ans[i]<<endl;
}
//洛谷P2709 小B的询问
//https://www.luogu.com.cn/problem/P2709