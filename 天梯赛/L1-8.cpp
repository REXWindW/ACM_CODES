#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
int dj[66]={0,0,0,0,0,0,
10000,36,720,360,80,252,108,72,54,180,
72,180,119,36,306,1080,144,1800,3600};
const int MAXN = 1e5+5;
int a[7][7];
void solve(){
    int tot = 0;
    rep(i,1,9) tot+=i;
    rep(i,1,3)
        rep(j,1,3){
            cin>>a[i][j];
            tot-=a[i][j];
        }
    rep(i,1,3)
        rep(j,1,3){
            if(a[i][j] == 0)a[i][j]=tot;
        }
    int x,y;
    rep(sdf,1,3){
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    int typ;
    int res = 0;
    cin>>typ;
    if(typ<=3){
        rep(i,1,3){
            res+=a[typ][i];
        }
    }
    else if(typ<=6){
        rep(i,1,3){
            res+=a[i][typ-3];
        }
    }
    else if(typ==7){
        res = a[1][1]+a[2][2]+a[3][3];
    }
    else res = a[1][3]+a[2][2]+a[3][1];
    //cout<<"res"<<res<<endl;
    cout<<dj[res]<<endl;
}
int main(){
    //rep(i,1,27){
    //    cout<<i<<' '<<dj[i]<<endl;
    //}
    solve();
}