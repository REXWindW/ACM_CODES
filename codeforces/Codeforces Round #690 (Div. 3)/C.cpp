#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
vector<int> res;
int maxx = 45;
int x;
void solve(){
    res.clear();
    cin>>x;
    if(x>maxx){
        cout<<-1<<endl;
        return;
    }
    repb(i,9,1){
        if(x>=i){
            //cout<<"in"<<i<<endl;
            x-=i;
            res.push_back(i);
        }
    }
    int siz = res.size();
    repb(i,siz-1,0){
        cout<<res[i];
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}