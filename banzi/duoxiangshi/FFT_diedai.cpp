#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 3e6+5;
const double Pi = acos(-1.0);
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
struct cplx{
    double x,y;
    cplx(double x=0,double y=0):x(x),y(y){}
    friend cplx operator + (cplx a,cplx b){return cplx(a.x+b.x,a.y+b.y);}
    friend cplx operator - (cplx a,cplx b){return cplx(a.x-b.x,a.y-b.y);}
    friend cplx operator * (cplx a,cplx b){return cplx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
}a[MAXN],b[MAXN];
int la,lb;
int rev[MAXN],lim,len;//len存二进制位数
//和递归FFT的limit不一样,这里的lim在FFT执行中是不变的
inline void FFT(cplx a[],int type){
    rep(i,0,lim-1) if(i<rev[i]) swap(a[i],a[rev[i]]);
    //按照位逆序后的数字大小排好序,因为是置换所以On就行
    rep(dep,1,log2(lim)){//第一层枚举层数
        int m = 1<<dep;//得到dep层每组的元素个数
        cplx Wn(cos(2.0*Pi/m),type*sin(2.0*Pi/m));//单位根
        for(int k=0;k<lim;k+=m){//第二层k表示每个m元组开始的点
            cplx w(1,0);
            rep(j,0,(m>>1)-1){
                cplx t = w*a[k+j+m/2];//蝴蝶操作,两两进行运算
                cplx u = a[k+j];
                //之前因为这句卡了好久,没这句的话a[k+j]的值改变了,a[k+j+m/2]就错了
                a[k+j] = a[k+j]+t;
                a[k+j+m/2] = a[k+j]-t;
                w = w*Wn;
            }
        }
    }
}
inline void init_rev(){//预处理rev位逆序置换数组
    rep(i,0,lim-1) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(len-1));//|和+作用是一样的
    //后面几位是上一个子问题的解向右移动一位,第一位即最底层按奇偶得出
}
int main(){
    la = read(),lb = read();
    rep(i,0,la) a[i].x = read();
    rep(i,0,lb) b[i].x = read();
    lim = 1,len = 0;
    while(lim<=la+lb) lim<<=1,len++;//一定要是2的幂
    init_rev();//计算位逆序顺序
    FFT(a,1);
    FFT(b,1);
    rep(i,0,lim-1) a[i] = a[i]*b[i];//点值表示法直接相乘
    FFT(a,-1);//现在变回去
    rep(i,0,la+lb) printf("%d ",(int)(a[i].x/lim+0.5));//还要除以n的
    printf("\n");
}