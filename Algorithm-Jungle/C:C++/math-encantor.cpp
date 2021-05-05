#include<stdio.h>
#include<string.h>
char z[57];
long long fc[26];
void fac(int n)
{
	int i;
	fc[0]=1;
	for(i=1;i<n;++i)
	   fc[i]=fc[i-1]*i;
}
long long KT(char b[],int n)
{
	fac(n);
	long long result=0;
	int count=0;
	int i,j;
	for(i=0;i<n;++i)
	{
		count=0;
		for(j=i+1;j<n;++j)
			if(z[j]<z[i])
				++count;
		result+=fc[n-i-1]*count;
	}
	return result;
}
int main()
{
	scanf("%s",z);
	printf("%lld",KT(z,strlen(z)));
	return 0;
}