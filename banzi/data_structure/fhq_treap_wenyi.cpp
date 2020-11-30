#include<iostream>
#include<ctime>
#include<vector>
#include<random>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1e5+5;
struct Node{
    int l,r;
    int val,key;
    int size;
    bool reverse;//旋转的懒惰标记
}fhq[MAXN];
int cnt,root;
mt19937 rnd(233);
vector<int>res;//因为行的末尾不能有空格所以我先用一个vector存着
inline int newnode(int val){
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size=1;
    return cnt;
}
inline void update(int now){
    fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size+1;
}
inline void pushdown(int now){
//如果当前节点的儿子有可能之后被动到,就需要向下传递reverse
    swap(fhq[now].l,fhq[now].r);
    fhq[fhq[now].l].reverse^=1;//儿子的懒惰标记0变1,1变0
    fhq[fhq[now].r].reverse^=1;
    fhq[now].reverse = 0;//之前疑惑这里为什么不用取反^1的
    //其实是因为如果now没有标记reverse,就不用执行pushdown
}
void split(int now,int siz,int &x,int &y){//按照大小分裂
//有点类似取第k大getnum的操作
    if(!now){x=y=0;return;}
    if(fhq[now].reverse) pushdown(now);//之后分裂操作可能碰到儿子,所以要pushdown
    if(fhq[fhq[now].l].size<siz){
        x = now;
        split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
    }
    else{
        y = now;
        split(fhq[now].l,siz,x,fhq[now].l);
    }
    update(now);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key){//这里其实用什么符号都行
        if(fhq[x].reverse) pushdown(x);
        fhq[x].r = merge(fhq[x].r,y);
        update(x);
        return x;
    }
    else{
        if(fhq[y].reverse) pushdown(y);
        fhq[y].l = merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
void reverse(int l,int r){//区间反转
//拆成三段,(1,l-1),(l,r),(r+1,n);
    int x,y,z;
    split(root,l-1,x,y);
    split(y,r-l+1,y,z);
    fhq[y].reverse^=1;
    root=merge(merge(x,y),z);    
}
void ldr(int now){//最后用中序遍历找到结果
    if(!now) return;
    if(fhq[now].reverse) pushdown(now);
    ldr(fhq[now].l);
    res.push_back(fhq[now].val);//推入结果的序列
    ldr(fhq[now].r);
}
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,1,n) root = merge(root,newnode(i));//因为i一定比之前出现的都大才可以这样
    int l,r;
    while(m--){
        cin>>l>>r;
        reverse(l,r);
    }
    res.clear();
    ldr(root);
    int siz = res.size();
    rep(i,0,siz-1){
        cout<<res[i];
        if(i!=siz-1) cout<<' ';
    }
    cout<<endl;
}
//AgOH说,平衡树也是可以处理序列(区间操作)问题的,一般使用的split都是这种按个数siz分裂的split
//这题里面有点线段树的味道,通过一个懒惰标记节省了很多没有必要的反转消耗的时间
//洛谷P3391 【模板】文艺平衡树
//https://www.luogu.com.cn/problem/P3391