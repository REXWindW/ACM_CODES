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

//注意1有两种！
//           0 1 2 3 4 5 6 7 8 9
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int a[16][10]={
    {1,1,1,0,1,1,1},//0
    {0,1,0,0,1,0,0},//1 1.1
    {1,0,1,1,1,0,1},//2
    {1,0,1,1,0,1,1},//3
    {0,1,1,1,0,1,0},//4
    {1,1,0,1,0,1,1},//5
    {1,1,0,1,1,1,1},//6
    {1,0,1,0,0,1,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,1,0,1,1},//9
    {0,0,1,0,0,1,0},//10 1.2
    {0,0,0,0,0,0,0}//empty//不能改变位数所以没有的！
};
int wa,wb,wc;//abc的位数
int fa[5],fb[5],fc[5];
int ga[5],gb[5],gc[5];
int dis(int f,int t){//返回从f到t需要移动多少根
    int ret = INF;
    int tmp = 0;
    if(t==1){
        rep(i,0,6)
            if(a[f][i]!=a[10][i]) tmp++;//和1,2比较
        ret = tmp;
    }
    tmp = 0;
    rep(i,0,6){
        if(a[f][i]!=a[t][i]) tmp++;
    }
    if(f==1){//f也有两种1的可能
        ret = min(ret,dis(10,t));
    }
    return min(tmp,ret);
}
int aa,bb,cc;
int eda,edb,edc,sta,stb,stc;
int tot_hc;//总共火柴数量
int res=INF;
int main(){
    cin>>aa>>bb>>cc;
    int ta = aa,tb = bb,tc = cc;
    //按位拆分
    eda=edb=edc=1;
    while(ta){
        tot_hc+=cnt[ta%10];
        fa[++wa]=ta%10;
        ta/=10;
        eda*=10;
    }
    while(tb){
        tot_hc+=cnt[tb%10];
        fb[++wb]=tb%10;
        tb/=10;
        edb*=10;
    }
    while(tc){
        tot_hc+=cnt[tc%10];
        fc[++wc]=tc%10;
        tc/=10;
        edc*=10;
    }
    //cout<<"tothc"<<tot_hc<<endl;
    sta = eda/10;
    if(sta==1) sta--;
    stb = edb/10;
    if(stb==1) stb--;
    stc = edc/10;
    if(stc==1) stc--;
    eda--,edb--;//a,b的枚举范围
    //cout<<"ran a"<<sta<<' '<<eda<<endl;
    //cout<<"ran b"<<stb<<' '<<edb<<endl;
    int kk;
    rep(i,sta,eda){
        rep(j,stb,edb){
            int ii=i,jj=j;
            int ia=0,ib=0,ic=0;
            int k = i+j;
            kk = k;
            int tmp_hc=0;
            while(ii){
                tmp_hc+=cnt[ii%10];
                ga[++ia]=ii%10;
                ii/=10;
            }
            while(jj){
                tmp_hc+=cnt[jj%10];
                gb[++ib]=jj%10;
                jj/=10;
            }
            while(kk){
                tmp_hc+=cnt[kk%10];
                gc[++ic]=kk%10;
                kk/=10;
            }
            if(tmp_hc!=tot_hc) continue;
            //保证火柴数量相同
            if(ia!=wa||ib!=wb||ic!=wc) continue;
            //保证位数相同
            //开始计算移动数
            int ret = 0;
            rep(q,1,wa){
                //cout<<dis(fa[q],ga[q])<<endl;
                ret+=dis(fa[q],ga[q]);
            }
            rep(q,1,wb){
                //cout<<dis(fb[q],gb[q])<<endl;
                ret+=dis(fb[q],gb[q]);
            }
            rep(q,1,wc){
                //cout<<dis(fc[q],gc[q])<<endl;
                ret+=dis(fc[q],gc[q]);
            }
            //cout<<"ok"<<i<<' '<<j<<' '<<k<<':'<<ret<<endl;
            res = min(res,ret);
        }
    }
    cout<<res/2<<endl;
}