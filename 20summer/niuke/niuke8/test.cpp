#include<iostream>
#include<algorithm>
using namespace std;
struct test{
	int num;
	friend bool operator > (test a,test b){
		return a.num < b.num;
	}
};
int main(){
	test x[2];
	cin>>x[0].num>>x[1].num;
	sort(x,x+1);
	cout<<x[0].num<<endl<<x[1].num<<endl;
}
