#include<iostream>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 77;
inline int idx(char c){
    return c-'a';
}
struct Node{
    int son[25],fail,cnt;
}trie[MAXN*26];
int ans[MAXN*26];
string s;
int n,cntt;
queue<int> q;
void insert(string &s){
    int siz = s.size();
    int u=1,v;
    rep(i,0,siz-1){
        v = idx(s[i]);
        if(!trie[u].son[v]) trie[u].son[v] = ++cntt;
        u = trie[u].son[v];
    }
    trie[u].cnt++;
}
void getfail(){
    rep(i,0,25) trie[0].son[i] = 1;
    int ufail,u = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front();q.pop();
        ufail = trie[u].fail;
        rep(i,0,25){
            if(!trie[u].son[i]){
                trie[u].son[i]=trie[ufail].son[i];
                continue;
            }
            trie[trie[u].son[i]].fail = trie[ufail].son[i];
        }
    }
}
void query(string &s){
    int siz = s.size();
    int u=1,v,k;
    rep(i,0,siz-1){
        v = idx(s[i]);
        k = trie[u].son[v];
        while(k){
            ans[k] += trie[k].cnt;
            k = trie[k].fail;
        }
        u = trie[u].son[v];
    }
}
void init(){
    rep(i,0,cntt){//先前有几个点现在清几个点
        trie[i].fail=trie[i].cnt = 0;
        rep(j,0,25) trie[i].son[j]=0;
    }
}
void solve(){
    init();
    rep(i,1,n){
        cin>>s;
        insert(s);
    }
    cin>>s;
    query(s);
    int maxx = 0;
    
}
int main(){
    while(cin>>n&&n!=0) solve();
}