#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 1e5+5;
const double alpha = 0.75;//平衡因子
struct Node{
    int l,r,val;
    int size,fact;//子树大小,子树内存在的节点数
    bool exist;//是否存在
}tzy[MAXN];
int cnt,root;//节点堆计数,根节点下标
void newnode(int &now,int val){//新建节点
    now = ++cnt;
    tzy[now].val=val;
    tzy[now].size=tzy[now].fact = 1;//初始化
    tzy[now].exist = 1;
}
bool imbalance(int now){//判断平衡
    //如果左右子树中的一个重量占比超过平衡因子,或者子树中假的点超过30%
    if(max(tzy[tzy[now].l].size,tzy[tzy[now].r].size)>tzy[now].size*alpha
    ||tzy[now].size-tzy[now].fact>tzy[now].size*0.3)
        return 1;
    else return 0;
}
vector<int> v;
void ldr(int now){//中序遍历
    if(!now) return;//到底了
    ldr(tzy[now].l);
    if(tzy[now].exist) v.push_back(now);//存在的点拎起来,不存在的丢掉
    ldr(tzy[now].r);
}
void lift(int l,int r,int &now){//递归分治把中间的点拎起来
    if(l==r){
        now = v[l];
        tzy[now].l=tzy[now].r = 0;//叶子节点
        tzy[now].size=tzy[now].fact = 1;
        return;
    }
    int m = (l+r)>>1;//找到中间节点;
    //特殊情况,如果是x 5 5 x x的话,相同的值本应该放在右边,这里却放到了左边
    while(l<m&&tzy[v[m]].val==tzy[v[m-1]].val)//左移,直到找到合适的点
        m--;
    now = v[m];//找到应该被拎起来的点
    //分治思想
    if(l<m) lift(l,m-1,tzy[now].l);//左边还有可以拎起来的,最后一个参数是为了把树接起来的
    else tzy[now].l = 0;
    lift(m+1,r,tzy[now].r);//右边一定有可以拎起来的
    tzy[now].size = tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
    tzy[now].fact = tzy[tzy[now].l].fact+tzy[tzy[now].r].fact+1;
}
void rebuild(int &now){//之前这里now忘了写引用
    v.clear();
    ldr(now);//得到中序遍历序列
    if(v.empty()){//所有的都是被假的点,特判
        now = 0;
        return;
    }
    lift(0,v.size()-1,now);
}
void update(int now,int end){//因为没有记录父亲的编号,所以只能头递归
    if(!now) return;
    if(tzy[end].val<tzy[now].val) update(tzy[now].l,end);
    else update(tzy[now].r,end);
    tzy[now].size=tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
}
void check(int &now,int end){//沿路径检查
    if(now==end) return;
    if(imbalance(now)){
        rebuild(now);//重构
        update(root,now);//重构后更新
        return;
    }
    if(tzy[end].val<tzy[now].val) check(tzy[now].l,end);
    else check(tzy[now].r,end);
}
void ins(int &now,int val){//递归插入节点
    if(!now){//now=0是没有节点的地方(空儿子)
        newnode(now,val);
        check(root,now);//检查插入后是否需要重构
        return;
    }
    tzy[now].size++;
    tzy[now].fact++;
    if(val<tzy[now].val) ins(tzy[now].l,val);
    else ins(tzy[now].r,val);
}
void del(int now,int val){
    if(tzy[now].exist&&tzy[now].val==val){//找到要删的了
        tzy[now].exist = 0;
        tzy[now].fact--;
        check(root,now);//检查删除后是否需要重构
        return;
    }
    tzy[now].fact--;//路径上的节点的fact都需要更新
    //这里是因为数据没有删除"不存在的点"的情况,所以可以这样写
    if(val<tzy[now].val) del(tzy[now].l,val);
    else del(tzy[now].r,val);
}
int getrank(int val){//查询第几大
    int now = root,rank = 1;
    while(now){
        if(val<=tzy[now].val) now = tzy[now].l;
        else{
            rank+=tzy[now].exist+tzy[tzy[now].l].fact;//加上当前点和左子树
            now = tzy[now].r;
        }
    }
    return rank;
}
int getnum(int rank){//查询第k小
    int now = root;
    while(now){
        if(tzy[now].exist&&tzy[now].exist+tzy[tzy[now].l].fact==rank) break;//找到
        else if(tzy[tzy[now].l].fact>=rank)
            now = tzy[now].l;
        else{
            rank-=tzy[now].exist+tzy[tzy[now].l].fact;//左子树没有去边找
            now = tzy[now].r;
        }
    }
    return tzy[now].val;
}
void solve(){
    int typ,hc;
    cin>>typ;
    if(typ==1){//插入
        cin>>hc;
        ins(root,hc);
    }
    else if(typ==2){//删除
        cin>>hc;
        del(root,hc);
    }
    else if(typ==3){//查询x的排名
        cin>>hc;
        cout<<getrank(hc)<<endl;
    }
    else if(typ==4){//查询排名为x的数
        cin>>hc;
        cout<<getnum(hc)<<endl;
    }
    else if(typ==5){//前驱
        cin>>hc;
        cout<<getnum(getrank(hc)-1)<<endl;
        //注意前驱和后继查询的区别,理一下逻辑其实很简单
    }
    else if(typ==6){//后继
        cin>>hc;
        cout<<getnum(getrank(hc+1))<<endl;
        //我一开始写的是getnum(getrank(hc)+1)
        //如果hc不在树里,就会出错
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
//我之前的一个疑问,tzy树有0这个假的点作为根,如果从root=0这个点重构了,root没了该怎么办
//后来想了想,在重构里now用的是引用,所以引用root的时候,重构时root会被改变
//即一开始root是一个val=0的假点,在root子树重构之后,root会被替换成一个真点
//洛谷 P3369 【模板】普通平衡树
//https://www.luogu.com.cn/problem/P3369