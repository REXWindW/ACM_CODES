#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const int MAXN = 1e6+5;
inline int idx(char c){return c-'a';}
struct Node{
    int son[26],flag,fail;
}trie[MAXN*10];
int n,cntt;
string s;
queue<int> q;
void insert(string &s){//字典树插入模式串
    int siz = s.size(),v,u = 1;//根节点开始
    rep(i,0,siz-1){
        v = idx(s[i]);
        if(!trie[u].son[v]) trie[u].son[v] = ++cntt;
        u = trie[u].son[v];
    }
    trie[u].flag++;//记数
}
void getfail(){//处理失配指针
    rep(i,0,25) trie[0].son[i] = 1;//虚节点0
    q.push(1);trie[1].fail = 0;
    //建一个虚节点0号节点,将1的所有儿子指向1，然后1的fail指向0就OK了
    int u,v,ufail;
    while(!q.empty()){
        u = q.front();q.pop();
        rep(i,0,25){
            v = trie[u].son[i];
            ufail = trie[u].fail;
            if(!v){trie[u].son[i]=trie[ufail].son[i];continue;}
            //如果这个分支不满足，则会和失配的情况类似去跳转
            trie[v].fail = trie[ufail].son[i];
            //((他父亲节点)的失配指针指向的节点)的(和这个节点字母相同的儿子)
            q.push(v);
        }
    }
}
int query(string &s){//匹配
    int siz = s.size(),u = 1,v,k,ans = 0;
    rep(i,0,siz-1){
        v = idx(s[i]);
        k = trie[u].son[v];//k用来跳fail
        while(k&&trie[k].flag!=-1){//找到了没标记的单词
            ans += trie[k].flag;trie[k].flag = -1;//计数,并标记走过
            k = trie[k].fail;//跳fail,如果一个串匹配成功,那它的fail一定也能匹配
        }
        u = trie[u].son[v];
    }
    return ans;
}
int main(){
    cntt = 1;//初始化cnt
    cin>>n;
    string hc;
    rep(i,1,n){
        cin>>s;insert(s);
    }
    getfail();
    cin>>s;
    cout<<query(s)<<endl;
}
//P3808 【模板】AC自动机（简单版）https://www.luogu.com.cn/problem/P3808
//https://www.luogu.com.cn/blog/juruohyfhaha/solution-p3808