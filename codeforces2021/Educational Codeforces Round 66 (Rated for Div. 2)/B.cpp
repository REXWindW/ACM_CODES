#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
typedef pair<ll,bool> plb;
#define ft first
#define sd second
#define mkp make_pair
int n;
string comd;
stack<plb>st;
ll now,res;
ll LINF = 1ll<<32;
void solve(){
    cin>>n;
    bool flag = 1;
    now=1;res=0;
    int tmp;
    rep(i,1,n){
        cin>>comd;
        if(comd=="for"){
            cin>>tmp;
            if(now<LINF){
                st.push(mkp(tmp,1));
                now*=tmp;
            }
            else{
                st.push(mkp(tmp,0));
            }
        }
        else if(comd=="end"){
            if(st.top().sd) now/=st.top().ft;
            st.pop();
        }
        else if(comd=="add"){
            if(now>=LINF){
                flag=0;
            }
            res+=now;
        }
    }
    if(res>=LINF||!flag){
        cout<<"OVERFLOW!!!"<<endl;
    }
    else cout<<res<<endl;
}

int main(){
    solve();
}