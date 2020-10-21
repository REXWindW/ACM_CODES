#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mkp make_pair
#define ft first
#define sd second
const int MAXN = 114514;
int n;
typedef pair<int,int> pii;
vector<pii> a;
vector<pii> b;
void solve(){
    a.clear();
    cin>>n;
    int hc;
    rep(i,1,n){
        cin>>hc;
        a.push_back(mkp(hc,i));
    }
    sort(a.begin(),a.end());
    if(a[0].ft==a[n-1].ft){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<a[0].sd<<' '<<a[n-1].sd<<endl;
        rep(i,1,n-2){
            if(a[i].ft!=a[0].ft) cout<<a[0].sd<<' '<<a[i].sd<<endl;
            else cout<<a[i].sd<<' '<<a[n-1].sd<<endl;
        }
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}