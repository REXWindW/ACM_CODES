#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
int n;
int a[MAXN];
int aa[2][MAXN];
int c[2],pre[2];
int prio;//优先
void solve(){
    prio=c[0]=c[1]=0;
    cin>>n;
    int flag = 0;
    pre[1]=pre[0]=-1;
    rep(i,1,n) cin>>a[i];
    aa[0][0]=aa[1][0]=a[0] = -1;
    /*
    rep(i,1,n){
        if(a[i]!=a[i-1]){//段首
            aa[prio][++c[prio]]=a[i];
            if(flag) prio^=1;
            flag = 0;
        }
        else{
            aa[prio][++c[prio]]=a[i];
            flag = 1;
        }
    }
    */
    rep(i,1,n){
        if(flag){
            if(aa[prio^1][c[prio^1]]!=a[i]){
                prio^=1;flag--;
            }
            else{//这种情况flag又变成2了
                flag=2;
            }
        }
        aa[prio][++c[prio]]=a[i];
        
        i++;
        while(a[i]==a[i-1]&&i<=n){
            aa[prio^1][++c[prio^1]]=a[i];
            flag = 2;
            i++;
        }
        i--;
    }
    int cnt = 0;
    rep(i,1,c[0])
        if(aa[0][i]!=aa[0][i-1]) cnt++;
    rep(i,1,c[1])
        if(aa[1][i]!=aa[1][i-1]) cnt++;
    cout<<cnt<<endl;
}

int main(){
    solve();
}