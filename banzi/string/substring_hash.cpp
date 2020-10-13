#include<iostream> 
using namespace std;
const int b = 131;
const int MAXN = 1e5 + 5;
typedef unsigned long long ull;
ull h[MAXN], pw[MAXN]; // h[k]存储字符串前k个字母的哈希值, pw[k]存储 b^k mod 2^64
//这里的模数M取的就是ull的上限2^64
char str[MAXN];

void init(int n){//初始化 
    pw[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        h[i] = h[i-1]*b + str[i];//做每个前缀的哈希值 
        pw[i] = pw[i-1]*b;//预处理b^k的值 
    }
}
// 计算子串 str[l ~ r] 的哈希值
ull get(int l, int r) {
    return h[r] - h[l-1]*pw[r-l+1];
}
int main() {
    int n, m;
    scanf("%d%d%s",&n,&m,str+1);//这样读入字符串第一位从1开始 
    init(n);
    while (m--) {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)!=get(l2,r2))
        	printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
//ACWing 841 给两个区间查询这两个子串是否相同