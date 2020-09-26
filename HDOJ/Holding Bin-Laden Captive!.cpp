#include<iostream>
using namespace std;

const int MAXN = 1e4+5;
bool c1[MAXN],c2[MAXN];
int mz[4] = {0,1,2,5};//记录面值 
int n[4];

int main(){
	while(cin>>n[1]>>n[2]>>n[3]){
		if(n[1]==0&&n[2]==0&&n[3]==0) break;
		int mn = n[1]+n[2]*2+n[3]*5;//计算最大的面值总和 
		//初始化
		for(int i=0;i<=mn;i++){
			c1[i]=0;c2[i]=0;
		}
		
		for(int i=0;i<=n[1];i++){
			c1[i]=1;
		}
		for(int i=2;i<=3;i++){
			for(int j=0;j<=mn;j++){
				for(int k=0;k<=n[i]&&j+k*mz[i]<=mn;k++){
					c2[j+k*mz[i]] = c2[j+k*mz[i]] | c1[j];//用布尔值来算
					//试过换成int，但是还是wa
				}
			}
			for(int ii=0;ii<=mn;ii++){
				c1[ii]=c2[ii];//交换左右的系数 
				c2[ii]=0;//清空c2 
			}
		}
		int x = 0;
		while(c1[x])x++;
		cout<<x<<endl;
	}
} 
