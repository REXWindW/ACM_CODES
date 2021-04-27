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
//Wo AK le
//qiandao easy
string ez="easy",qd="qiandao";
char c[114514];
int n,m;
void solve(){
    cin>>n>>m;
    int cnt = 0;
    getchar();
    rep(i,1,n){
        fgets(c,114514,stdin);
        int siz = strlen(c);
        //cout<<siz<<endl;
        siz--;
        bool flag = 0;
        rep(i,0,siz-1){
            if(i+3<siz){
                flag = 1;
                rep(j,0,3){
                    if(ez[j]!=c[i+j]){flag=0;break;}
                }
                if(flag) break;
            }
            if(i+6<siz){
                flag = 1;
                rep(j,0,6){
                    if(qd[j]!=c[i+j]){flag=0;break;}
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) continue;
        if(cnt==m){cout<<c;return;}
        cnt++;
    }
    cout<<"Wo AK le"<<endl;
}
int main(){
    solve();
}