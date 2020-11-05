#include<bits/stdc++.h>
char c[60],b[100000];
int main()
{
	int n,i,sign=0;
	while(~scanf("%d",&n))
	{
		gets(c);
		for(i=0;i<n;++i)
		{
			if(c[0]>'a'&&c[0]<'z'||c[0]=='_')
			{
				++sign;
				goto l;
			}
			else
			{
				printf("no\n");
				goto end;
			}
			l:for(i=0;c[i]!='\0';++i)
			{
				if(c[i]>'0'&&c[i]<'9'||c[i]>'a'&&c[i]<'z'||c[i]=='_')
				{
				continue;
				}
				else
				{
				printf("no\n");
				goto end;
				}
				 printf("yes\n");
			end:;		
			}
		}
	}
	return 0;
}