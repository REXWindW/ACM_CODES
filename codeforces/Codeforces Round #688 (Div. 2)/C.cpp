#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
#define mkp make_pair
#define ft first
#define sd second
const int MAXN = 2020;
int n;
vector<pii> a[10];
int upmax[10],downmax[10],leftmax[10],rightmax[10];
void solve(){
    char hc;
    cin>>n;
    rep(i,0,9){
        upmax[i]=n+1,downmax[i]=0,leftmax[i]=n+1,rightmax[i]=0;//四条边最近的几个点
        a[i].clear();
    }
    int idx;
    rep(i,1,n){
        rep(j,1,n){
            cin>>hc;
            idx = hc-'0';
            a[idx].push_back(mkp(i,j));//推推推
            upmax[idx] = min(i,upmax[idx]);
            downmax[idx] = max(i,downmax[idx]);
            leftmax[idx] = min(j,leftmax[idx]);
            rightmax[idx] = max(j,rightmax[idx]);
        }
    }
    //我的想法是枚举一个长边中的节点，然后找另一侧最远的节点
    int siz;
    int res;
    int up,down,left,right;
    rep(k,0,9){
        res = 0;
        siz = a[k].size();
        rep(i,0,siz-1){
            up=down=left=right=0;
            up = max((n-a[k][i].sd),(a[k][i].sd-1))*(a[k][i].ft-upmax[k]);
            down = max((n-a[k][i].sd),(a[k][i].sd-1))*(downmax[k]-a[k][i].ft);
            left = max((n-a[k][i].ft),(a[k][i].ft-1))*(a[k][i].sd-leftmax[k]);
            right = max((n-a[k][i].ft),(a[k][i].ft-1))*(rightmax[k]-a[k][i].sd);
            res = max(res,max(up,max(down,max(left,right))));
        }
        cout<<res<<' ';
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}