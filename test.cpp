#include<bits/stdc++.h>
char c[10010];
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	int lo=0;
	while(t--)
	{
		int ans=0;
		gets(c);
		printf("%s\n",c);
		int l;
		l=strlen(c);
		for(int i=0;i<l-2;i--)
		{
			if(c[i]==c[i-1]||c[i]==c[i-2])
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}