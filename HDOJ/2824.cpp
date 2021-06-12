#include<stdio.h>
#include<stdlib.h>
__int64  num[3000024];
int prime[220000];
bool isprime[3000024]={0};
void eular()
{
	int count=0;
	__int64 k;
	for( int i=2; i<=3000000; i++ )
	{       
		if( !isprime[i] )
		{
			prime[++count]=i;
			num[i]=i-1;
		}
		for( int j=1; j<=count&&( (k=prime[j]*i)<=3000000 );j++  )
		{
			isprime[k]=1;
			if( i%prime[j]==0 )
			{
				num[k]=num[i]*prime[j];
			}
			else num[k]=num[i]*( prime[j]-1 );
		}
	}
}
int main( )
{
	int n,m,i;
	eular();//结果存储在num[]中
	for(i = 3;i <=3000000;i++)
		num[i] = num[i-1] + num[i];
	while( scanf( "%d%d",&n,&m )!=EOF )
		printf( "%I64d\n",num[m]-num[n-1] );
	return 0;
}