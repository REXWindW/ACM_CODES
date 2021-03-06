#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int inf= 0x7FFFFFFF;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
int dp[310][310];
string depth[]={"数据表","地区","学校","学院","班级","学生"};
struct rcd{
    int num;
    int depth;
    string name;
};
struct node{
    int l,r;
    rcd v;
    node(){l=0,r=0;}
}tree[110000];
int cnt;//搜索计数
int stk[110000];
pair<int,string> stk2[110000];
int tail,tree_tail,tail2;
int flg[110000];
int srt[110000];
vector<int> v;
string tmp;//搜索用
int calc(string a,string b){
    return b.find(a)!=b.npos;
}
void dfs(int now,int dep){
    if(!flg[now]){
        for(int i=0;i<v.size();i++){
            if(v[i])
                cout<< "︱ ";
            else cout<<"   ";
        }
        if(tree[now].l) cout<<"├─ ";
        else cout<<"└─ ";
        cout<<tree[now].v.num<<' '<<depth[dep]<<':'<<tree[now].v.name<<endl;
        if(tree[now].r){
            if(tree[now].l)
                v.push_back(1);
            else v.push_back(0);
            dfs(tree[now].r,dep+1);
            v.pop_back();
        }
    }
    if(tree[now].l) dfs(tree[now].l,dep);
}
void flsh(){
    dfs(0,0);
    return;
}
void insert(int pos,string name){
    int dd=tree[pos].v.depth;
   if(!tree[pos].r){
        tree[pos].r=++tree_tail;
        stk[++tail]=tree_tail;
        tree[tree_tail].v=(rcd){tree_tail,dd+1,name};
        tree[tree_tail].r=tree[tree_tail].l=0;
        return;
    }
    pos=tree[pos].r;
    while(tree[pos].l)
        pos=tree[pos].l;
    tree[pos].l=++tree_tail;
    stk[++tail]=tree_tail;
    tree[tree_tail].v=(rcd){tree_tail,dd+1,name};
    tree[tree_tail].r=tree[tree_tail].l=0;
    cout<<"插入成功"<<endl;
}
void change(){
    cout<<"请输入你要插入的位置 和要修改的名称"<<endl;
    int pos;
    string name;
    cin>>pos>>name;
    stk[++tail]=0;
    stk2[++tail2]=make_pair(pos,tree[pos].v.name);
    tree[pos].v.name=name;
}
void dfs2(int now){//用于搜索功能
    if(now==0) return;
    if(flg[now]==0){//没被删除的情况
        dfs2(tree[now].r);//访问儿子
        if(calc(tmp,tree[now].v.name)){cout<<'!'<<endl;srt[++cnt]=now;}
    }
    dfs2(tree[now].l);//都访问兄弟
}
void search(){
    system("cls");
    cout<<"请输入你要查找的字符串"<<endl;
   	cin>>tmp; 
    cnt=0;
    dfs2(tree[0].r);
    cout<<"为您找到以下字段:"<<endl;
    for(int i=1;i<=min(10,cnt);i++){
        cout<<tree[srt[i]].v.num<<' '<<depth[tree[srt[i]].v.depth]<<":"<<tree[srt[i]].v.name<<endl;
    }		
}
inline void del(){
    cout<<"请输入你要删除的字段编号"<<endl;
    int pos;
    cin>>pos;
    stk[++tail]=pos;
    flg[pos]=1;
    return;
}
void rev(){
    if(stk[tail]){
        flg[stk[tail--]]^=1;
    }else{
        tree[stk2[tail2].first].v.name=stk2[tail2].second;
        tail2--;
    }
}
void init(){
    insert(0,"杭州");//1
    insert(0,"北京");//2
    insert(1,"杭电");//3
    insert(2,"北大");//4
    insert(2,"清华");//5
    insert(3,"计算机学院");//6
    insert(3,"卓越学院");//7
    insert(3,"电子学院");
    insert(7,"和尚班");//9
}
int main(){
    //system("chcp 65001");
    system("cls");
    tree[0].v.name="根目录/";
    tree[0].v.num=0;
    cout<<"是否放入作者预置的树信息?(1/0)"<<endl;
    int sbrsb; cin>>sbrsb; if(sbrsb) init();
    while(1){
        system("cls");
        flsh();
        cout<<"学生管理系统by Rand0w & REXWIND"<<endl;
        cout<<"1.插入"<<endl;
        cout<<"2.删除"<<endl;
        cout<<"3.修改"<<endl;
        cout<<"4.查询"<<endl;
        cout<<"5.回退"<<endl;
        cout<<"6.打印"<<endl;
        cout<<"请输入你的操作:";
        cout.flush();
        int chice;
        cin>>chice;
        if(chice==1){
            cout<<"请输入你要插入的位置 和要插入的名称"<<endl;
            int pos;string name;
            cin>>pos>>name;
            insert(pos,name);
        }
        else if(chice==2)
            del();
        else if(chice==3)
            change();
        else if(chice==4)
            search();
        else if(chice==5){
            if(!tail) cout<<"回退失败"<<endl;
            else{
                rev();
                cout<<"回退成功"<<endl;
            }
        }
        cout<<"按下任意键回到主菜单"<<endl;
        system("pause");
    }
}