#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 114514;
int now[114];
char a[114][5140];
char st[MAXN];
int top;
int n,m,sm;
vector<char> res;
void push(int x){
    st[++top] = x;
}
int pull(){
    return st[top--];
}
void solve(){
    top = 0;
    cin>>n>>m>>sm;
    rep(i,1,n){
        now[i] = 1;
        rep(j,1,m) cin>>a[i][j];
    }
    int hc;
    while(cin>>hc&&hc!=-1){
        //cout<<"now"<<':'<<top<<endl;
        if(hc==0){//zhua
            if(top==0) continue;//nothing
            res.push_back(pull());
        }
        else{
            if(now[hc]>m)//轨道空了
                continue;
            if(top==sm)
                res.push_back(pull());
            push(a[hc][now[hc]]);
            now[hc]++;
        }
    }
    int siz = res.size();
    rep(i,0,siz-1) cout<<res[i];
    cout<<endl;
}
int main(){
    solve();
}