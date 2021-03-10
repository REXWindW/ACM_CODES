#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int a,b,k;
const int MAXN = 114514*2;
int x[MAXN],y[MAXN];
void solve(){
    scanf("%d%d%d",&a,&b,&k);
    if(b==0){printf("NO\n");return;}
    if(k==0){
        printf("YES\n");
        rep(i,1,b) printf("1");
        rep(i,1,a) printf("0");
        cout<<endl;
        rep(i,1,b) printf("1");
        rep(i,1,a) printf("0");
        printf("\n");
        return;
    }
    if(a+b-1<=k){printf("NO\n");return;}
    //构造成11xx1-10xx1的形式，其余再后部用x填冲
    if(b==1||a==0){printf("NO\n");return;}
    //一般情况
    int aa,bb;
    printf("YES\n");
    //x
    aa = a-1;bb = b-2;
    printf("11");
    rep(i,1,k-1){
        if(aa>0){printf("0");aa--;}
        else if(bb>0){printf("1");bb--;}
    }
    printf("0");
    while(aa>0) printf("0"),aa--;
    while(bb>0) printf("1"),bb--;
    printf("\n");
    //y
    aa = a-1;bb = b-2;
    printf("10");
    rep(i,1,k-1){
        if(aa){printf("0");aa--;}
        else if(bb>0){printf("1");bb--;}
    }
    printf("1");
    while(aa) printf("0"),aa--;
    while(bb) printf("1"),bb--;
    printf("\n");
}

int main(){
    solve();
}