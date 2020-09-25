#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 10000
const int maxnode=2e6+5;
const int sigma_size=26;//字母开26，如果是数字之类的则开10 

char s[MAXN];

struct Trie{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz; 
	
	Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}//初始化，此时只有根节点
	
	int idx(char c){
		return c-'a';//同理如果是数字则换成c-'0' 
	} 
	
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++){
			int c=idx(s[i]);
			if(!ch[u][c]){//节点不存在(u没有子节点字母为c)这个u和c的意义全然不同,u是节点编号,c是字符编号 
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;//中间节点，附加信息为0，当然也可以用其他的来标记比如-1 
				ch[u][c]=sz++;//画好边，并且总结点数++ 
			}
			u=ch[u][c];//光标往下走 
		}//这里出来就是u已经到单词节点(即一个单词的末尾字符)上了 
		val[u] = v;//insert时的第二个参数v,可以附加信息 
	} 
	bool find(char *s,int len){//查找串s长度不超过len的前缀,改一改成int也可以返回附加值 
		int u=0;
		for(int i=0;i<len;i++){
			if(s[i]=='\0') break;
			int c=idx(s[i]);
			if(!ch[u][c]) break;
			u=ch[u][c];
			if(val[u]!=0) return true;
		} 
		return false; 
	} 
}T;//之前因为T定义在main里面所以一直运行不了，发现这个结构体和数组有点类似
//定义为全局函数可以开得更大！ 
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	Trie T;
	while(n--){
		scanf("%s",s);
		getchar();
		T.insert(s,1);
	}
	scanf("%d",&n);
	getchar();
	while(n--){
		scanf("%s",s);
		getchar();
		if(T.find(s,strlen(s))) cout<<"yes!"<<endl;
		else cout<<"no!"<<endl;
	}
}