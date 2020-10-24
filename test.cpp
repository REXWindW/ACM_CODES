#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b)
{
	return a>b;//不写比较函数就  默认升序  ，写的话就必须写a>b,可以理解为前一个元素大于后一个元素，为降序形式 
}
int main ()
{
	int a[11]={9,8,77,67,93,2,5,7,3,1};
	int i;
	sort(a,a+10,com);
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}