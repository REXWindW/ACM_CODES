#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//直接暴力
int rev[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int hh,mm;
int a[6];
int b[6];
int nowh,nowm;
int h,m;
bool cal(int h,int m){//求镜像值
    a[1]=h/10;a[2]=h%10;
    a[3]=m/10;a[4]=m%10;
    rep(i,1,4){
        b[i]=rev[a[4-i+1]];
        if(b[i]==-1) return 0;
    }
    h = b[1]*10+b[2];
    m = b[3]*10+b[4];
    if(h<hh&&m<mm) return 1;
    else return 0;
}
void solve(){
    scanf("%d%d",&hh,&mm);
    scanf("%d:%d",&h,&m);
    //cout<<"!";
    if(cal(h,m)){
        printf("%02d:%02d\n",h,m);
        return;
    }
    nowh=h;nowm=m;
    nowm++;
    if(nowm>=mm){nowm=0;nowh++;}
    if(nowh>=hh){nowh=0;}
    while(nowh!=h||nowm!=m){
        if(cal(nowh,nowm)){
            printf("%02d:%02d\n",nowh,nowm);
            return;
        }
        nowm++;
        if(nowm>=mm){nowm=0;nowh++;}
        if(nowh>=hh){nowh=0;}
    }
    printf("00:00\n");
}

int main(){
    cal(52,28);
    int z;
    cin>>z;
    while(z--) solve();
}