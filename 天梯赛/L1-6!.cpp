#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
char ms[66]="chi1 huo3 guo1";
int n;
int minn;
#define INF 0x3f3f3f3f
const int MAXN = 233;
char hc[MAXN];
void solve(){
    int z = 0;
    minn = INF;
    int cnt = 0;
    int siz = strlen(ms);
    while(1){
        fgets(hc+1,222,stdin);
        int n = strlen(hc+1);
        if(hc[1]=='.'&&n==2) break;
        z++;
        rep(i,1,n-siz+1){
            bool flag = 1;
            rep(j,0,siz-1){
                if(hc[i+j]!=ms[j]) {flag = 0;break;}
            }
            if(flag){
                minn = min(minn,z);
                cnt++;
            }
        }
    }
    cout<<z<<endl;
    if(minn==INF) cout<<"-_-#"<<endl;
    else cout<<minn<<' '<<cnt<<endl;
}

int main(){
    solve();
}