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
int a[MAXN],b[MAXN];
bool vis[MAXN];
int n,m,ya,yb;//y1y2其实没卵用
void solve(){
    cin>>n>>ya;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cin>>m>>yb;
    rep(j,1,m){
        cin>>b[j];
    }
    sort(b+1,b+1+m);
    int dd,st,cnt,maxx=0;
    rep(ii,1,n){
        rep(k,1,m) vis[k]=0;//清空
        rep(jj,1,m){
            if(vis[jj]) continue;
            cnt = 0;
            dd = abs(a[ii]-b[jj]);
            if(dd){
                st = a[ii];
                rep(i,1,n)
                    if((a[i]-st)%(dd*2)==0) cnt++;
                st = b[jj];
                rep(j,1,m){
                    if((b[j]-st)%(dd*2)==0){
                        cnt++;
                        vis[j] = 1;
                    }
                }
            }
            else{
                st = a[ii];
                rep(i,1,n)
                    if(a[i]==st) cnt++;
                rep(j,1,m){
                    if(b[j]==st) cnt++;
                }
            }
            cout<<"check"<<a[ii]<<' '<<b[jj]<<' '<<cnt<<endl;
            maxx = max(maxx,cnt);
        }
    }
    cout<<maxx<<endl;
}

int main(){
    solve();
}