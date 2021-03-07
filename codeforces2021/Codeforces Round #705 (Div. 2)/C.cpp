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
//把n分组
//初期先贴着填,如果后来贴着填字母太多的话，就把最后一个贴着填的变成大一点的字母!
//abcd这个，ab贴着填，c不够贴着了，而且c比之前出现的都大
const int MAXN = 114514;
string s;
int n,k;
int a[MAXN];
int b[MAXN];
int cnt[30];
inline int idx(char c){return c-'a';}
void fixx(){//填充剩余
    rep(i,0,28){
        if(cnt[i]>=k){
            cnt[0]+=(cnt[i]-cnt[i]%k);//全都回退到a
            cnt[i]%=k;
        }
    }
    int now = 0;
    rep(i,0,n-1){
        if(b[i]!=-1) continue;
        while(cnt[now]==0) now++;
        b[i]=now;
        cnt[now]--;//填数
    }
}
void solve(){
    rep(i,0,29) cnt[i]=0;
    cin>>n>>k;
    cin>>s;
    //cout<<"!";
    //-1情况
    if(n%k){
        cout<<-1<<endl;return;
    }
    if(k==1){cout<<s<<endl;return;}
    bool flag = 1;
    rep(i,1,n-1)
        if(s[i]!='z'){flag=0;break;}
    if(flag){
        cout<<-1<<endl;
        return;
    }
    //正常情况
    rep(i,0,n-1){
        a[i]=idx(s[i]);//转数字
        b[i]=-1;//打上空标记
    }
    int zu = n/k;//有多少组
    int prep=-1;//上一个新增组的起始位置和字样
    rep(i,0,n-1){
        if(cnt[a[i]]){//无需新增组
            cnt[a[i]]--;
            b[i]=a[i];
        }
        else if(cnt[a[i]]==0){//新增组
            if(zu==0){//无法新增组,改动最近一处新增组,也可以是换一个大点的到这里
                int upp = -1;
                rep(j,a[i]+1,28)//往上找合适的组
                    if(cnt[j]){upp=j;break;}
                if(upp!=-1){//如果往上的组刚好有剩余！
                    cnt[upp]--;
                    b[i]=upp;//填上去
                    fixx();
                    break;
                }
                else{//如果往上一组没有剩余
                    int tmp=b[prep];
                    cnt[tmp]++;
                    b[prep]=tmp+1;
                    rep(j,prep+1,i-1){
                        cnt[b[j]]++;//回退回来
                        b[j]=-1;
                    }
                    cnt[tmp+1]+=cnt[tmp];//这个时候可能tmp+1会超过k,可以让组重新回去
                    cnt[tmp]=0;
                    cnt[tmp+1]--;
                    //剩下来的全都转换成a
                    fixx();
                    break;
                }
            }
            else{//增加新的一组
                zu--;
                cnt[a[i]]+=k;
                b[i]=a[i];
                cnt[a[i]]--;
                prep=i;//记录最近一次新增的组位置,方便之后改的时候能尽量靠后使字典序尽可能小
            }
        }
    }
    rep(i,0,n-1) cout<<(char)('a'+b[i]);
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}