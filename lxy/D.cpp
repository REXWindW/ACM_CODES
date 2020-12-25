#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 114514;
ll jc[MAXN],x;
ll mx = 1;
void solve(){
    cin>>x;
    int px = upper_bound(jc+1,jc+mx+1,x)-jc-1;
    if(px==1) cout<<px<<endl;
    else{
        cout<<(jc[px]-x>x-jc[px-1]?px:px-1)<<endl;
    }
}
int main(){
    freopen("D_in.txt","r",stdin);
    freopen("D_out.txt","w",stdout);
    jc[0] = 0;
    for(mx=2;jc[mx-1]<2e13;mx++){
        jc[mx] = jc[mx-1]+mx*mx;
    }
    int z;cin>>z;
    while(z--) solve();
}