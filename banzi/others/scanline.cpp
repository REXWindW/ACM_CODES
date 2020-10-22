#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long 
#define ls (x<<1)
#define rs (x<<1|1)//这种方法感觉还挺好的

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 2e5+5;//这里要开n的两倍
//线结构体
struct Line{
    ll l,r,h;
    int qz;//记录位置和权值
    bool operator < (Line &rhs){
        return h < rhs.h;
    }
}line[MAXN];
int n;
ll x1,y1,x2,y2;
ll X[MAXN];
//线段树
struct Segt{
    int l,r;//是X的下标,即离散化后的
    int sum;//sum是被完全覆盖的次数
    ll len;//len是区间内被盖住的长度
    //因为每次查询都是查询根节点,所以这边不需要懒惰标记
}t[MAXN<<3];//一个边有两个点,所以这里要开8倍
void build(int x,int l,int r){
    t[x].l = l;t[x].r = r;
    t[x].len = t[x].sum = 0;
    if(l==r) return;//到了叶子节点
    int mid = (l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void push_up(int x){
    int l = t[x].l,r = t[x].r;
    if(t[x].sum) t[x].len = X[r+1]-X[l];//x的区间是X[l]到X[r+1]-1
    else t[x].len = t[ls].len + t[rs].len;//合并儿子的信息
}
void update(int x,int L,int R,int v){//这里的LR存的是实际值
    //这里如果是线段L,R,线段树上是L到R-1的部分维护
    int l = t[x].l,r = t[x].r;
    if(X[r+1]<=L||R<=X[l]) return;//加等于,不然会搞到无辜的线
    if(L<=X[l]&&X[r+1]<=R){
        t[x].sum += v;//修改覆盖次数
        push_up(x);
        return;
    }
    update(ls,L,R,v);
    update(rs,L,R,v);
    push_up(x);
}
int main(){
    cin>>n;
    rep(i,1,n){
        cin>>x1>>y1>>x2>>y2;
        X[2*i-1] = x1,X[2*i] = x2;//一会儿离散化要用的,这里存实际值
        line[2*i-1] = Line{x1,x2,y1,1};//开始的线
        line[2*i] = Line{x1,x2,y2,-1};//结束的线
    }
    n<<=1;//line的数量是四边形数量的2倍
    sort(line+1,line+1+n);
    sort(X+1,X+1+n);
    int tot = unique(X+1,X+n+1)-(X+1);//去除重复相邻元素,并且tot记录总数
    build(1,1,tot-1);//为什么是tot-1?
    //因为线段树只需要维护X[1]到X[tot]-1这一段的,实际长度是向右贴的
    ll res = 0;
    rep(i,1,n-1){//每次高度是line[i+1].h-line[i].h,所以是到n-1就行
        update(1,line[i].l,line[i].r,line[i].qz);//扫描线加入线段树
        res += t[1].len*(line[i+1].h-line[i].h);
    }
    cout<<res<<endl;
}
//洛谷P5490 【模板】扫描线
//https://www.luogu.com.cn/problem/P5490