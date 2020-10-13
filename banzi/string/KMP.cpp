const int MAXN = 2e6+5;
int pi[MAXN];//MAXN记得开大一点,因为这里要存到m+n+1长度的 
vector<int> res;//储存答案
 
void getpi(const string &s){ //求s的前缀函数
	pi[0]=0;
	int j=0;
	rep(i,1,s.length()-1){
		while(j>0&&s[i]!=s[j]) j=pi[j-1];//找到合适且最长的j 
		if(s[i]==s[j])j++;//能成功匹配的情况 
		pi[i]=j;
	}
}

void kmp(string s,string t){ //在主串t中找模式串s 
	getpi(s+'#'+t);
	int n=(int)s.length(),m=(int)t.length();
	rep(i,n+1,m+n+1-1)
		if(pi[i]==n) res.push_back(i-2*s.size()); //i-2n计算得左端点 
}