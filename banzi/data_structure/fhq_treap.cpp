#include<iostream>
#include<ctime>
#include<random>
using namespace std;
const int MAXN = 1e5+5;
struct Node{
    int l,r;
    int val,key;//val维护平衡树,key维护大根堆
    int size;
}fhq[MAXN];
int cnt,root;
mt19937 rnd(233);//产生速度快,周期大的高质量随机数
inline int newnode(int val){
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size = 1;
    return cnt;//返回编号
}
inline void update(int now){//更新大小
    fhq[now].size = fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
void split(int now,int val,int &x,int &y){//树分裂,通过传引用告诉函数应该接在哪里
//x是x树的"接口",y是y树的"接口" : 分裂后x树的值<=val,y树>val
    if(!now){x=y=0;return;}
    if(fhq[now].val<=val){
        x = now;
        //左子树都比val小,直接把当前节点连带左子树接到x上,下一步继续去右子树找
        split(fhq[now].r,val,fhq[now].r,y);//x的接口变成r位置,y的接口不变
    }
    else{
        y = now;
        split(fhq[now].l,val,x,fhq[now].l);
    }
    update(now);
}
int merge(int x,int y){//传入时保证x树中的val全部小于y树!
    if(!x||!y) return x+y;//如果有一方为0,返回另一方
    if(fhq[x].key>fhq[y].key){//维护key大根堆的性质,根一定比儿子大
        fhq[x].r = merge(fhq[x].r,y);//y的val比x大,所以放右边
        update(x);
        return x;//返回值是和上一层接起来
    }
    else{
        fhq[y].l = merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
int x,y,z;//因为之后会经常用到所以这里先定义
inline void ins(int val){
//按val分xz树,新节点y,合并xy,再和z合并
    split(root,val,x,y);
    root = merge(merge(x,newnode(val)),y);//第一次插入的点也会在这里被变成root,所以不用担心
}
inline void del(int val){
//1.按val分成xz,按val-1把x分成xy 2.删掉y树的根(只删去一个val) 3.合并xyz
    split(root,val,x,z);
    split(x,val-1,x,y);
    y = merge(fhq[y].l,fhq[y].r);
    root = merge(merge(x,y),z);
}
inline int getrank(int val){
//按照val-1分xy,x的大小+1即val排名
    split(root,val-1,x,y);
    int res = fhq[x].size+1;
    root = merge(x,y); 
    return res;
}
inline int getnum(int rank){//普普通通找数字
    int now = root;
    while(now){//询问rank有可能大于总结点数量,这时候会返回0
        if(fhq[fhq[now].l].size+1==rank)break;
        else if(fhq[fhq[now].l].size>=rank) now=fhq[now].l;
        else{
            rank-=fhq[fhq[now].l].size+1;
            now = fhq[now].r;
        }
    }
    return fhq[now].val;
}
inline int pre(int val){
//按val-1分xy,找x中最大的点
    split(root,val-1,x,y);
    int now = x;
    while(fhq[now].r) now = fhq[now].r;//一直往右边找
    int res = fhq[now].val;
    merge(x,y);
    return res;
}
inline int nxt(int val){
    split(root,val,x,y);
    int now = y;
    while(fhq[now].l) now = fhq[now].l;
    int res = fhq[now].val;
    merge(x,y);
    return res;
}
int main(){
    int t,typ,x;
    cin>>t;
    while(t--){
        cin>>typ>>x;
        if(typ==1) ins(x);
        else if(typ==2) del(x);
        else if(typ==3) cout<<getrank(x)<<endl;
        else if(typ==4) cout<<getnum(x)<<endl;
        else if(typ==5) cout<<pre(x)<<endl;
        else if(typ==6) cout<<nxt(x)<<endl;
    }
}
//同样思考了一下root初始值的事情,一开始的root是无效值0,这时候是不会执行split的
//在插入第一个数值后,root就变成了这个新的节点
//洛谷 P3369 【模板】普通平衡树
//https://www.luogu.com.cn/problem/P3369