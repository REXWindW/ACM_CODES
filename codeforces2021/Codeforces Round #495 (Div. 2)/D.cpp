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
const int MAXN = 1114514;
int n,hc,x,y;
int cnt[MAXN],cnt2[MAXN];
void solve(){
    cin>>n;
    int maxx = 0;
    rep(i,1,n){
        cin>>hc;
        cnt[hc]++;
        maxx = max(maxx,hc);
    }
    if(n==1&&cnt[0]){
        cout<<"1 1\n1 1\n";return;
    }
    rep(i,1,maxx){
        if(cnt[i]<4*i){
            x = i;break;
        }
    }
    if(!x){
        cout<<-1<<endl;return;
    }
    int j;
    //maxx = i+j -x-y;
    bool flag = 0;
    rep(i,1,n-1){
        if(n%i) continue;
        j=n/i;
        y = i+j-x-maxx;
        if(y<=0) continue;
        //开始验证
        flag = 1;
        rep(ii,1,i)
            rep(jj,1,j)
                cnt2[abs(ii-x)+abs(jj-y)]++;
        rep(k,1,maxx){
            if(cnt[k]!=cnt2[k])flag = 0;
            cnt2[k]=0;
        }
        if(flag){
            cout<<i<<' '<<j<<endl;
            cout<<x<<' '<<y<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){solve();
}