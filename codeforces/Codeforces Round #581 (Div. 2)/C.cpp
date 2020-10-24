#include<iostream>
#include<vector>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int MAXN = 666;
const int INF = 0x3f3f3f3f;
const int MAXM = 1e6+5;
int d[MAXN][MAXN];
int a[MAXM];
int n;
void solve(){
    cin>>n;
    char hc;
    rep(i,1,n){
        rep(j,1,n){
            cin>>hc;
            if(hc=='1') d[i][j]=1;
            else d[i][j]=INF;
            if(i==j) d[i][j] = 0;
        }
    }
    //floyd;
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);    
            }
        }
    }
    int m;
    cin>>m;
    rep(i,1,m) cin>>a[i];
    vector<int> res;
    int st,cnt,now;
    res.push_back(a[1]);
    st = 1;
    rep(i,2,m){
        cnt = 1;
        now=i;
        i++;
        while(i<=m&&d[a[now]][a[i]]==1&&d[a[st]][a[i]]==cnt+1){
            now = i;
            cnt++;
            i++;
        }
        i--;
        res.push_back(a[i]);
        st = i;
    }
    int siz = res.size();
    cout<<siz<<endl;
    rep(i,0,siz-1){
        cout<<res[i]<<' ';
    }
    cout<<endl;
}

int main(){
    solve();
}