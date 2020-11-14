#include<iostream>
using namespace std;
#define rep(i,a,b) for(int (i)=a;i<=b;i++)

const int MAXN = 1e4;
int c1[MAXN+1];
int c2[MAXN+1];

int main(){
	int n;
	while(cin>>n){ 
		for(int i=0;i<=n;i++){//初始化 
			c1[i]=0;
			c2[i]=0;
		}
		for(int i=0;i<=n;i++){
			c1[i]=1;//面值为一元的
		}
		for(int i=2;i<=n;i++){//枚举邮票的面值(一共有几组括号 
			for(int j=0;j<=n;j++){//枚举左边次数为0到次数为n的项 
				for(int k=0;j+k<=n;k+=i){//右边的乘过来，枚举放几枚
				//次数大于n的就不用管了 
					c2[j+k]+=c1[j];
				}
			}
			for(int i=0;i<=n;i++){//最左边两个括号完成处理 
				c1[i]=c2[i];//把c2算出来的值挪到左边作为下一次的左边 
				c2[i]=0;//清空c2记录下一次括号相乘的结果 
			}
		}
		cout<<c1[n]<<endl; 
	} 
} 