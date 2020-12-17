#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
const int MAXN = 123;
int n,m;
string s;
string a[MAXN];
string b[MAXN];
int cntnode;
int siz[MAXN];
bool flag[MAXN];
map<string,int> mp[1145];
int dfs(int now){
    //cout<<"now"<<now<<endl;
    int ret = 0;
    map<string,int>::reverse_iterator iter;
    for(iter = mp[now].rbegin(); iter!=mp[now].rend();iter++){
        if(iter->second==0) continue;
        //cout<<"find"<<iter->first<<flag[iter->second]<<endl;
        if(flag[iter->second]==0) ret++;
        else{
            //cout<<"into"<<iter->first<<endl;
            ret+=dfs(iter->second);
        }
    }
    return ret;
}
void solve(){
    cntnode = 0;
    mp[0].clear();
    cin>>n>>m;
    getline(cin,s);
    rep(i,1,n){
        getline(cin,s);
        int siz = s.size();
        string hc;
        int now = 0;//当前节点
        rep(i,0,siz-1){
            if(s[i]=='/'){
                //cout<<hc<<' ';
                if(mp[now][hc]){
                    now = mp[now][hc];
                }
                else{
                    mp[now][hc]=++cntnode;
                    mp[cntnode].clear();//chushihua
                    //cout<<"newnode"<<hc<<"number"<<cntnode<<endl;
                    flag[cntnode] = 0;//默认都可以忽略
                    now = mp[now][hc];
                }
                hc.clear();
            }
            else hc = hc+s[i];
        }
        //处理末尾
        //cout<<hc<<' ';
        if(mp[now][hc]){
            now = mp[now][hc];
        }
        else{
            mp[now][hc]=++cntnode;
            mp[cntnode].clear();//chushihua
            //cout<<"newnode"<<hc<<"number"<<cntnode<<endl;
            flag[cntnode] = 0;//默认都可以忽略
            now = mp[now][hc];
        }
        hc.clear();
        //cout<<endl;
    }
    rep(i,1,m){
        getline(cin,s);
        int siz = s.size();
        string hc;
        int now = 0;//当前节点
        rep(i,0,siz-1){
            if(s[i]=='/'){
                if(mp[now][hc]){
                    now = mp[now][hc];
                    flag[now] = 1;//路径上都标记不能忽略
                    //cout<<hc<<' ';
                    hc.clear();
                }
                else break;
            }
            else hc+=s[i];
        }
        //cout<<endl;
    }
    flag[0] = 1;
    int res = dfs(0);
    cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
/*
1
3 2
a/b/c
a/b/d
b/c/d
a/b/e/f
b/e
*/