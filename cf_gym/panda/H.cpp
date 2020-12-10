#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f

int k,n;
const int MAXN = 1e6+5;
int a[MAXN];
int b[MAXN];//问号位应该为？
int res;
inline int lowbit(int x){return x&-x;}
void solve(){
    n = 1;
    rep(i,1,k) n*=2;//确定总位数
    n--;
    char hc;
    //读入，清空b
    rep(i,0,n){
        cin>>hc;
        a[i] = (hc=='1');
        b[i] = 0;
    }
    int tmp;
    rep(i,1,n){
        if(i!=lowbit(i)){//不是问号位
            b[i] = a[i];
            tmp = i;
/*
            cout<<"a"<<i<<endl;
*/
            while(tmp){//处理相关问号位
/*
                cout<<lowbit(tmp)<<endl;
*/
                b[lowbit(tmp)]^=a[i];
                tmp-=lowbit(tmp);
            }
        }
    }
    vector<int> nott;//统计不正确的问号位

    rep(i,0,n) cout<<b[i];
    cout<<endl;

    rep(i,1,n){
        if(b[i]!=a[i]) nott.push_back(i);
    }
    cout<<"nott size="<<nott.size()<<endl;
    rep(i,1,n)
        b[0]^=b[i];
    if(nott.size()==0){
        if(b[0]==a[0])cout<<"good"<<endl;
        else cout<<"d("<<0<<") is changed"<<endl;
        return;
    }
    else if(nott.size()==1){
        if(b[0]!=a[0]){//说明改了一个？
            res = nott[0];
            cout<<"d("<<res<<") is changed"<<endl;
            return;
        }
        else{//说明broken
            cout<<"broken"<<endl;
            return;
        }
    }
    if(nott.size()==2){
        if(b[0]==a[0]){//说明改了一个
            res = nott[0]^nott[1];
            cout<<"d("<<res<<") is changed"<<endl;
            return;
        }
        else{//改了两个
            cout<<"broken"<<endl;
            return;
        }
    }
    else{//大于2的情况
        int siz = nott.size();
        res = 0;
        rep(i,0,siz-1) res^=nott[i];
        if(b[0]!=a[0]){
            cout<<"d("<<res<<") is changed"<<endl;
            return;
        }
        else{
            cout<<"broken"<<endl;
            return;
        }
    }
}

int main(){
    while(cin>>k) solve();
}