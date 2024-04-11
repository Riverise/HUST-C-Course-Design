#include<stdio.h>
void change(char *s);
void sort(char ss[][10],int i,int *a);
void remade(char ss[][10],int i);
void main()
{
	char *s;
	gets(s);
	change(s);
}
void change(char *s)
{
	char ss[10][10];
	int a[10];
	int i;
	for(i=0;*s!='\0';i++)
	{
		for(a[i]=0;*s!=' '&&*s!='\0';s++,a[i]++)
		{
			*(ss[i]+a[i])=*s;
		}
		*(ss[i]+a[i])='\0';
		if(*s!=0)
			s++;
	}
	sort(ss,i,a);
	remade(ss,i);
}
void sort(char ss[][10],int i,int *a)
{
	int j,k,m;
	char *temp;
	for(j=0;j<i;j++)
	{
		for(k=0;k<i-j-1;k++)
		{
			if(a[k]>a[k+1])
			{
				for(m=0;ss[k][m]!='\0'||ss[k][m+1]!='\0';m++)
				{
					temp[m]=ss[k][m];
					ss[k][m]=ss[k+1][m];
					ss[k+1][m]=temp[m];
				}
			}
		}
	}
}
void remade(char ss[][10],int i)
{
	char *s,*temp;
	temp=s;
	int k,j;
	for(k=0;k<i;k++,s++)
	{
		for(j=0;ss[k][j]!='\0';j++,s++)
		{
			*s=ss[k][j];
		}
		*s=' ';
	}
	*s='\0';
	puts(temp);
}