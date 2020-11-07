#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const int MAXN = 1e5+5;
int jdbh[MAXN];//记录第i个模式串对应的节点编号
int cntcx[MAXN];//记录第i个模式串出现的次数
inline int idx(char c){return c-'a';}
struct Node{
    int son[26],flag,fail;//cnt记录次数,flag记录编号
    void clr(){
        memset(son,0,sizeof(son));
        flag=0;
    }
}trie[MAXN*10];
int n,cntt;//cntt记录总点数
string s,ms[166];
int maxx;
queue<int>q;
inline void insert(string &s,int num){
    int siz = s.size(),v,u=1;
    rep(i,0,siz-1){
        v = idx(s[i]);
        if(!trie[u].son[v]){trie[u].son[v] = ++cntt;trie[cntt].clr();}
        u = trie[u].son[v];
    }
    trie[u].flag = num;//标记为单词,flag记录编号
    //保证每个模式串只出现一次
    cntcx[num] = 0;
    jdbh[num] = u;//记录当前单词对应的节点编号
}
inline void getfail(){
    rep(i,0,25) trie[0].son[i] = 1;
    trie[0].flag = 0;
    q.push(1);
    trie[1].fail = 0;
    int u,v,ufail;
    while(!q.empty()){
        u = q.front();q.pop();
        rep(i,0,25){
            v = trie[u].son[i];
            ufail = trie[u].fail;
            if(!v){trie[u].son[i]=trie[ufail].son[i];continue;}//画好一条跳fail的路
            trie[v].fail = trie[ufail].son[i];
            q.push(v);
        }
    }
}
inline void query(string &s){
    int siz = s.size(),u = 1,v,k;
    rep(i,0,siz-1){
        v = idx(s[i]);
        k = trie[u].son[v];
        while(k){
            if(trie[k].flag){
                cntcx[trie[k].flag]++;//计数
                maxx = max(maxx,cntcx[trie[k].flag]);
            }
            k = trie[k].fail;//跳fail
        }
        u = trie[u].son[v];//这一句其实也有跳fail的功能，很精妙
    }
}
inline void solve(){
    cntt = 1;
    trie[0].clr();
    trie[1].clr();
    rep(i,1,n){
        cin>>ms[i];
        insert(ms[i],i);
    }
    getfail();
    cin>>s;
    maxx = 0;
    query(s);
    cout<<maxx<<endl;
    rep(i,1,n){
        if(cntcx[i]==maxx) cout<<ms[i]<<endl;
    }
}
int main(){
    while(cin>>n&&n!=0) solve();
}
//洛谷 P3796 【模板】AC自动机（加强版）
//https://www.luogu.com.cn/problem/P3796