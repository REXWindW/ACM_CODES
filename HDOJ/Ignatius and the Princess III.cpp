#include<iostream>
using namespace std;
#define rep(i,a,b) for(int (i)=a;i<=b;i++)

const int MAXN = 1e4;
int c1[MAXN+1];
int c2[MAXN+1];

int main(){
	int n;
	while(cin>>n){ 
		for(int i=0;i<=n;i++){//��ʼ�� 
			c1[i]=0;
			c2[i]=0;
		}
		for(int i=0;i<=n;i++){
			c1[i]=1;//��ֵΪһԪ��
		}
		for(int i=2;i<=n;i++){//ö����Ʊ����ֵ(һ���м������� 
			for(int j=0;j<=n;j++){//ö����ߴ���Ϊ0������Ϊn���� 
				for(int k=0;j+k<=n;k+=i){//�ұߵĳ˹�����ö�ٷż�ö
				//��������n�ľͲ��ù��� 
					c2[j+k]+=c1[j];
				}
			}
			for(int i=0;i<=n;i++){//���������������ɴ��� 
				c1[i]=c2[i];//��c2�������ֵŲ�������Ϊ��һ�ε���� 
				c2[i]=0;//���c2��¼��һ��������˵Ľ�� 
			}
		}
		cout<<c1[n]<<endl; 
	} 
} 
	
  
