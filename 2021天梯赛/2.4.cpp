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
vector<int> e[MAXN];//存边
int cundang[114];
int n,m;
void solve(){
    cin>>n>>m;
    int tmp,hc;
    rep(i,1,n){
        cin>>tmp;
        e[i].push_back(-1);//无效点顶住0位置
        while(tmp--){
            cin>>hc;
            e[i].push_back(hc);
        }
    }
    //开始游戏
    int typ,jj;
    int now = 1;//开始剧情点
    rep(t,1,m){
        cin>>typ>>jj;
        if(typ==0)
            now = e[now][jj];//移动
        else if(typ==1){
            cundang[jj] = now;
            //cout<<"cundang at";
            cout<<now<<endl;
        }
        else if(typ==2){
            now = cundang[jj];
        }
    }
    //cout<<"finally at";
    cout<<now<<endl;
}
int main(){
    solve();
}