#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
map<vector<int>,int> mp;
typedef pair<int,vector<int>> pp;
vector<pp> res;
vector<int> vec;
int n,m;
#define INF 0x3f3f3f3f
void solve(){
    cin>>n>>m;
    int hc;
    rep(i,0,m-1) vec.push_back(0);
    rep(i,1,n){
        rep(j,0,m-1){
            cin>>hc;
            vec[j] = hc;
        }
        //cout<<"check";
        //rep(i,0,m-1) cout<<vec[i]<<' ';
        //cout<<endl;
        mp[vec]++;
    }
    map<vector<int>,int>::iterator it;
    for(it=mp.begin();it!= mp.end();it++){
        res.push_back(mkp(INF-it->sd,it->ft));
    }
    sort(res.begin(),res.end());
    int rs = res.size();
    cout<<rs<<endl;
    rep(i,0,rs-1){
        cout<<INF-res[i].ft;
        rep(j,0,m-1) cout<<' '<<res[i].sd[j];
        cout<<endl;
    }
}
int main(){
    solve();
}