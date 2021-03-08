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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

const int MAXN = 114514;
string s;
int n,k;
int a[MAXN];
int cnt[30];
int sum[30][MAXN];//前缀和
inline int idx(char c){return c-'a';}
inline bool check(int pos){
    if(a[pos]=='z'-'a') return 0;//z不能往上移动
    int summ = 0;
    sum[a[pos]][pos]--;
    sum[a[pos]+1][pos]++;
    rep(i,0,28){
        summ+=(sum[i][pos]+k-1)/k*k;
    }
    //cout<<"check"<<pos<<"summ"<<summ<<endl;
    sum[a[pos]][pos]++;
    sum[a[pos]+1][pos]--;
    if(summ<=n){
        sum[a[pos]][pos]--;
        sum[a[pos]+1][pos]++;
        a[pos]=a[pos]+1;
        return 1;
    }
    //也可以上探
    if(summ-k<=n&&sum[a[pos]+1][pos]%k==0){//想办法减少一组
        int up = 0;
        rep(i,a[pos]+1,28){
            if(sum[i][pos]%k){//前面还有剩的
                up = i;break;
            }
        }
        if(up==0)return 0;
        sum[a[pos]][pos]--;
        sum[up][pos]++;
        a[pos]=up;
        return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>k;
    cin>>s;
    if(n%k){
        cout<<-1<<endl;
        return;
    }
    rep(j,0,28){cnt[j]=0;sum[j][0]=0;}
    rep(i,1,n){
        a[i]=idx(s[i-1]);
        rep(j,0,28) sum[j][i]=sum[j][i-1];
        sum[a[i]][i]++;//统计一下前缀和
    }
    bool flag = 1;
    rep(i,0,28)
        if(sum[i][n]%k){flag=0;break;}
    if(flag){cout<<s<<endl;return;}//可以直接出s的情况
    int res = 0;
    repb(i,n,1) if(check(i)){res = i;break;}
    int tot = n-res;
    rep(i,0,28){
        cnt[i]=(sum[i][res]+k-1)/k*k-sum[i][res];
        tot -= cnt[i];
    }
    if(tot%k!=0){cout<<"彩笔，你算法写假了"<<endl;}
    cnt[0]+=tot;
    int now=0;
    rep(i,res+1,n){
        while(cnt[now]==0) now++;
        a[i]=now;
        cnt[now]--;
    }
    rep(i,1,n) cout<<(char)(a[i]+'a');
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}